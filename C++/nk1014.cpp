#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int maxlen = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> lastpos(n+1,-1);
    vector<pair<int ,int>> answ(n);
    for (int l = 0, r = 0; r < n; ++r) {
        // 如果当前元素 a[r] 在窗口内已存在（即上次出现位置 >= l），则移动左指针到重复位置的下一个
        if (lastpos[a[r]] >= l) {
            l = lastpos[a[r]] + 1;
        }
        lastpos[a[r]] = r;
        int nowlen = r - l + 1;//左右都能算错?
        if(nowlen > maxlen) {
            maxlen = max(maxlen,nowlen);
            answ.clear();
            pair<int,int> m(l+1,r+1);
            answ.push_back(m);
        }
        else if(nowlen == maxlen){
            pair<int,int> m(l+1,r+1);
            answ.push_back(m);
        }
    }

    for(auto p : answ){
        cout<< p.first << ' ' << p.second <<endl;
    }
}
