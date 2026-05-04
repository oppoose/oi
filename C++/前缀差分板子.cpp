#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a(n+10);

    a[0] = 0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pos[i]=a[i]-a[i-1];
    }
    int q;cin>>q;//对区间a[l,r]加d
    while(q--){
        int l,r;cin>>l>>r;
        int d;cin>>d;
        pos[l]+=d;
        pos[r+1]-=d;
    }
    for(int i = 1; i <= n; i++){
        a[i] = a[i-1] + p[i];
    }
}