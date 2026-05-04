#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main(){
    int l,n;
    cin>>l>>n;
    vector<pair<int,int>> p(2*n);
    
    for(int i = 0 ; i < n; i++){
        cin>>p[i].first>>p[i+n].first;//不重要必须差n的下标,最后会排序!
        p[i].second = 1;p[i+n].second = -1;
    }
    sort(p.begin(), p.end(), cmp);//记住sort最后一个是.end,不是最后一个元素!
    //让他们在数轴上正常排列,而不是跳跃的存储(堆也有类似的性质)
    int cnt = 0;
    int ans = 0;
    for(int i = 1; i < 2*n; i++){
        cnt += p[i].second;
        if(cnt == 1 && p[i].second == 1){
            ans += p[i].first - p[i-1].first - 1;
        }
    }
    ans += p[0].first+ l - p[2*n-1].first;
    cout << ans << endl;
    return 0;
}