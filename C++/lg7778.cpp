#include <bits/stdc++.h>
using namespace std;
int num = 998244353 ;
int qpow(int n,int k){
    if(k == 1) return n;
    else if(k == 0) return 1;
    else {
        int p = qpow(n,k>>1)%num;
        p = (p * p)%num ;
        if(k & 1)  p = (p * n)%num;;
        return p;
    }

} 
struct ty{
    int x;
    int y;
}a[1000010];
bool cmp(ty a,ty b){
    return a.x < b.x;
}
int main(){
    int n,v;
    cin>>n>>v;
    int t = n;
    while(t--) cin>>a[t].x>>a[t].y;

    sort(a,a+n,cmp);
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += (a[i+1].x - a[i].x )*(a[i+1].x - a[i].x ) + (a[i+1].y - a[i].y )*(a[i+1].y - a[i].y );
    }
    int sum0 = sum * qpow(v*v,num-2) %num;
    cout<<sum0;
}