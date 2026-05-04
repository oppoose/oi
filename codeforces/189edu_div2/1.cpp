#include <iostream>
using namespace std;
#define int long long
void so(){
    int y,x;
    cin>>x>>y;
    int t = y/x;
    if(t==2){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}
#undef int
int main(){
    int q;cin>>q;
    while(q--){
        so();
    }
    return 0;
}