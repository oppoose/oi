#include <bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    while(n--){
        int sum = 0;
        int maxn = -1000000;
        for(int i = 0; i < 7; i++){
            int t;
            cin>>t;
            sum+=t;
            maxn = max(maxn,t);

        }
        cout<<-(sum - maxn) + maxn<<endl;
    }
}