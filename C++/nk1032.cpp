#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a(n+10);
    vector<vector<int>> sum(n+10,vector<int> (41));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int j = 0; j < 31; j++){
        sum[0][j] = 0;
        for(int i = 1; i <= n; i++){
            sum[i][j] = sum[i-1][j];
            if(((a[i]>>j) & 1 ) == 1){
                sum[i][j] = sum[i-1][j] + 1;
            }
        }
    }
    int q;cin>>q;
    int r,l;
    int x;
    while(q--){
        cin>>l>>r;
        x = 0;
        for(int i = 0; i < 31; i++){
            
            if((sum[r][i] - sum[l-1][i])*2 < l - r + 1){
                x = x | (1<<i);
            }
        }
        cout<<x<<endl;
    }
}