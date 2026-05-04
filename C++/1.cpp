#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;cin>>n;
        vector<int> a(n);
        vector<pair<int,int>> b(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int p = 0;
        while(a[p] = p) p++;
        int l = p;
        while(a[l] != l) l++;
        int r = l - 1;
        b.push_back({l,r});
    }
}