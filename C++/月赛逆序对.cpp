#include <bits/stdc++.h>
using namespace std;
int heb(int a,int b){
    if(b==a+1){
        cout<<"? "<<a<<" "<<b<<endl;cout.flush();
        int ans;
        cin>>ans;
        if(ans==1){
            return a;
        }
        else return b;
    }

    cout<<"? "<<a<<" "<<b<<endl;cout.flush();
    int ab;
    cin>>ab;
    cout<<"? "<<a<<" "<<b-1<<endl;cout.flush();
    int ab1;
    cin>>ab1;
    if(ab - ab1 == b - a){
        return b;
    }
    else return a;
}
int so(int l, int r){
    int mid = (l+r)/2;

    if(l==r) return l;
    if(l==r-1){
        cout<<"? "<<l<<" "<<r<<endl;
        cout.flush();
        int ans;
        cin>>ans;
        if(ans == 1){
            return l;
        }
        else return r;
    }
    int a = so(l,mid);
    int b = so(mid+1,r);
    return heb(a,b);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans = so(1,n);
        cout<<"! "<<ans<<endl;cout.flush();
    }
}//这个做法超过了5n^2修改为单侧的递归

