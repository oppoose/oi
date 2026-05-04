#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
long long a[maxn];
long long b[maxn];
long long sum[maxn];

int main(){
    int n;cin>>n;
    sum[0] = 0;
    for(int i = 0 ; i < n;i++){
        cin>>a[i];
        sum[i + 1] = sum[i] + a[i];
    }//sum i 从a1加到ai  (1为起始)
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    long long maxb = -1e7;
    vector<int> back;//合法的b的下标,升序
    for(int i = 0; i < n; i++){
        maxb = max(maxb,b[i]);
        if(b[i] != maxb) b[i] = 0;
        else back.push_back(i);
    }
    int p = n;
    long long ans = 0;
    int size = back.size();
    for(int i = size - 1; i >=0; i--){
        ans+= b[back[i]]*(sum[p]-sum[back[i]+1]+ a[back[i]]);
        p = back[i];
    }
    cout<<ans;
}