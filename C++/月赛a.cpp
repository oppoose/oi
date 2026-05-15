#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        vector<int> a(26,0);
        for(int i = 0; i < s.length(); i++){
            a[s[i] - 'a']++;
        }
        if(a[20] == 0 || a[5] == 0 || a[25] == 0){
            for(int i = 0; i < 26; i++){
                while(a[i] != 0){
                    char x = 'a' + i;
                    cout<<x;
                    a[i]--;
                }
            }
            break;
        }
        for(int i = 0; i < 20; i++){
            while(a[i] != 0){
                char x = 'a' + i;
                cout<<x;
                a[i]--;
            }
        }
        for(int i = 21; i < 26; i++){
            while(a[i] != 0){
                char x = 'a' + i;
                cout<<x;
                a[i]--;
            }
        }
        while(a[20] != 0){
            char x = 'a' + 20;
            cout<<x;
            a[20]--;
        }
        cout<<endl;
    }

}