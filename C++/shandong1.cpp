#include <bits/stdc++.h>
using namespace std;
struct ty{
    int a;
    int b;
    int na;
}p[200010];
bool cmp(ty a,ty b){
    if(a.a==b.a){
        return a.b < b.b;
    }
    return a.a > b.a;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            cin>>p[i].a>>p[i].b;
            p[i].na = i;
        }
        sort(p+1,p+n+1,cmp);
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(sum <= p[i].b){
                sum++;
                ans.push_back(p[i].na);
            }
            
        }
        cout<<sum<<endl;
        if (!ans.empty()) {
            cout << ans[0];                     
            for (int i = 1; i < (int)ans.size(); ++i)
                cout << ' ' << ans[i];          
        }
        cout<<endl;
    }

}