#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    int cntr = 0,cntc = 0;

    cin>>n>>m>>x;
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //行列搞反了
    vector<vector<int>> a(m,vector<int>(n));//改mn全都一起改,这里没改
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == x) cntr++;
        }
        if(cntr >= (n+1)/2) cntc++;
        cntr = 0;//又犯这个错误,清零
    }
    if(cntc >= (m+1)/2){    
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
//四次提交,最后ac,改字母容易改一部分忘改全部,状态变量记得清零