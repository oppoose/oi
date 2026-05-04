//https://ac.nowcoder.com/acm/problem/50243
#include<bits/stdc++.h>
using namespace std;
int n;
int v[65], a[65];
bool cmp(int b, int c){
return b > c;
}
bool dfs(int num, int rest, int len, int now){
//剩下的小棍子数量，当前大棍剩下的长度
//枚举的大棍长度,拼接当前大棍的第now根小棍子
if(0 == num && 0 == rest)  //小棍子全部拼完且没有剩余长度
    return true;
if(0 == rest){             //拼下一根大棍
    rest = len;
    now = 0;
}
for(int i = now; i < n; i++){
    if(v[i]) continue;       //已使用
    if(a[i] > rest) continue;//这根小棍大于剩余长度,放不下，pass
    v[i] = 1;
    if(dfs(num - 1, rest - a[i], len, i))
        return true;
    v[i] = 0;//回溯
    if(rest == len || rest == a[i])
        break;             //第一根或最后一根小棍不行，说明当前枚举的len行不通
    while(a[i] == a[i + 1])
        i++;               //与当前长度一致的小棍就不需要再尝试了
}
return false;
}
int main(){
cin>>n;
int sum = 0, i;
for(i = 0; i < n; i++){
    cin>>a[i];
    sum += a[i];
}
sort(a, a + n, cmp);         //从最长的小棍子开始拼接
for(i = a[0]; i <= sum; i++){//从最长的小棍长度开始枚举
    if(sum % i != 0) continue;//假设的大棍不能被总长整除，不可行！
    if(dfs(n, i, i, 0)) break;
}
cout<<i<<endl;
return 0;
}