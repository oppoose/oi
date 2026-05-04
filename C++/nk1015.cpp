#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int> a(26,0);
    vector<int> b(26,0);
    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            a[ch - 'a'] = 1;
        }
    }
    int len = s.length();
    for(int i = 0; i < len; i++){
        s[i] = s[i] - 'a';
    }
    for(int i = 0; i < 26; i++){
        if(a[i] == 0){
            cout<<-1;
            return 0;
        }
    }
    int l = 0,r = 0;
    int sum = 0;
    int minlen = 1e8;
    while(r < len){
        while(sum < 26 && r < len){
            if(b[s[r]] == 0){
                sum += 1;
            }
            b[s[r]]++;
            ++r;
        }
        
        while(l < r && sum == 26){
            b[s[l]]--;
            if(b[s[l]]==0){
                sum--;
                minlen = min(minlen,r - l);
            }
            ++l;
        }
    }
    if (minlen == 1e8) cout<<-1;
    else cout<<minlen;
}