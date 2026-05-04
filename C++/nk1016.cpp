#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    vector<int> a(n + 1);
    a[0] = 0;
    for(int i = 1; i < n + 1; i++){
        int p;
        cin>>p;
        a[i] = a[i-1] + p;
    }
    int i = 0, j = 0;
    int sum = 0;
    int maxnum;
    while(j < n + 1){
        sum = a[j] - a[i];//[i,j]区间里所有元素之和,第i,第j之间的距离(起始0)
        while(sum > a[n]/2){
            maxnum = max(maxnum,a[n] - sum);//更新最大长度
            i++;
            sum = a[j] - a[i];
        }
        maxnum = max(maxnum,sum);//再次更新
        j++;
    }
    cout<<maxnum;
}