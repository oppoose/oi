#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int n; cin>>n;
    int len = s.length();
    vector<vector<int>> a(len+10, vector<int> (40,-1));//a[i][j] 在字符串第i个的时候第j个字母的位置
    

    for(int i = len - 1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            a[i][j] = a[i+1][j];
        }
        a[i][s[i] - 'a'] = i;
    }
    //cout << "start" << endl;
    string p;
   
    while(n--){
        cin>>p;
        int flag = 0;
        int j = 0,i = 0;
        while(i < p.length() && j != -1){
            
            if(a[j+1][p[i] - 'a'] == -1){
                flag = 1;
                cout << "No" <<endl;
                break;
            }
            j = a[j+1][p[i] - 'a'];
            i++;
        }
        if(flag == 0) cout << "Yes";
    }
}