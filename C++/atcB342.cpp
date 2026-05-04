#include <bits/stdc++.h>
using namespace std;
int main(){
    int len;
    cin>>len;
    string s;
    cin>>s;
    string ans(len, ' ');
    vector<int> pos[26];  // 26个小写字母，每个对应一个vector
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            pos[s[i] - 'a'].push_back(i);
        }
    }
    int t;
    cin>>t;
    char ch1,ch2;
    vector<int> map(26); // 映射关系，初始为0-25
    for(int i = 0; i < 26; i++){
        map[i] = i;
    }
    while(t--){
        cin>>ch1>>ch2;
        if(ch1 == ch2) continue; // 如果两个字符相同，跳过
        map[map[ch1 - 'a']] = map[ch2 - 'a'];//更新映射关系
    }
    //根据映射关系,将pos中的位置重新分配到新的字符上
    for(int i = 0; i < 26; i++){
        if(!pos[i].empty()){
            map[i] = map[map[i]]; // 递归更新映射关系，确保所有映射都指向最终字符
        }
        
    }
    for(int i = 0 ; i < 26; i++){
        if(!pos[i].empty()){
            //ans[x in pos[i]] = 'a' + i; 
            for(int x : pos[i]){
                ans[x] = 'a' + i;
            }
        }
    }
    cout<<ans;
    return 0;
}