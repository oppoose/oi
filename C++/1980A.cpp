#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int sum = 0;
    int xl;
    vector<int> qu(7);
    cin>>n;
    string p;
    while(n--){
        sum = 0;
        qu.assign(7,0);
        cin>> xl;
        int m;
        cin>>m;// 比赛局数
        cin>>p;
        //input//
        for(char x : p){
            if(x >= 'A' && x <= 'G') {
                qu[ x - 'A']++;
            }
        }
        for(int i : qu){
            if(i < m){
                sum += m - i; 
            }
        }
        cout << sum << '\n';
    }
}