#include <bits/stdc++.h>
using namespace std;

bool check_swap(vector<int>& a, int n, int l1, int r1, int l2, int r2) {
    vector<int> b(n + 10);
    int idx = 1;
    for (int i = 1; i < l1; ++i) b[idx++] = a[i];
    for (int i = l2; i <= r2; ++i) b[idx++] = a[i];
    for (int i = r1 + 1; i < l2; ++i) b[idx++] = a[i];
    for (int i = l1; i <= r1; ++i) b[idx++] = a[i];
    for (int i = r2 + 1; i <= n; ++i) b[idx++] = a[i];
    for (int i = 1; i <= n; ++i) if (b[i] != i) return false;
    return true;
}

int main(){
    int q;
    cin>>q;
    while(q--){
        int n;cin>>n;
        vector<int> a(n+10, 0);
        vector<int> pos(n+10, 0); //
        vector<pair<int,int>> b;

        for(int i = 1; i <= n; i++){
            cin>>a[i];
            pos[a[i]] = i; //
        }

        int l = 1,p = 1,cnt = 0;
        while(p <= n && l <= n){
            p = l;
            while(p<=n && a[p] == p) p++;
            l = p;
            while(l<=n && a[l] != l) l++;
            int r = l - 1;
            if(r >= p){
                b.push_back({p,r});
                cnt++;
            }
        }

        if(cnt == 0){
            cout<<"Yes\n";
            continue;
        }

        if(cnt>=3){
            cout << "No\n";
            continue;
        }

        if(cnt==2){
            int le0 = b[0].first;
            int ri0 = b[0].second;
            int le  = b[1].first;
            int ri  = b[1].second;

            if(check_swap(a, n, le0, ri0, le, ri)) cout <<"Yes\n";
            else cout<<"No\n";
            continue;
        }

        //这里逻辑错误
        if(cnt==1){
            int L = b[0].first;
            int R = b[0].second;

            int p = pos[R]; // R 在哪
            int q = pos[L]; // L 在哪

            if(L <= p && p < q && q <= R &&
               check_swap(a, n, L, p, q, R)){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }
}