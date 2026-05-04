#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int x; cin>>x;
        int flag = 0;
        for(int i = 0 ; i < x; i++){
            if(flag)cout<<" ";
            cout<<i+1<<" "<<3*x-2*i-1<<" "<<3*x-2*i;
            flag = 1;
        }
        cout<<endl;
    }
}