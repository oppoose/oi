#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        vector<int> a(t);
        for(int i = 0; i < t; i++){
            cin>>a[i];
        }
        int maxx = 0;
        for(int i = 0;i < t; i++){
            for(int j = i+1; j < t; j++){
                maxx = max(a[i]^a[j],maxx);
            }
        }
        cout<<maxx<<endl;
    }
}