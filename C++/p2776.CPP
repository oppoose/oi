#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cont,qunt;

    cin>>cont>>qunt;

    vector<int> a(cont); 

    for(int i = 0 ; i < cont ; i++){
        cin>>a[i];
    }//按数字进组

    vector<queue<int>> quenequ(qunt); //队列数组
    queue<int> order; //队列顺序
    
    int num;
    cin>>num;//操作数量
    int inp; //push数字
    while(num--){
        string s; //操作名
        cin>>s;

        if(s == "push"){
            cin >> inp;

//            quenequ[a[inp]].push(inp); //逻辑混乱,第一遍你先push检查empty肯定非空,这样order永远为空;

            if(quenequ[a[inp]].empty()){
                order.push(a[inp]);
            }
            quenequ[a[inp]].push(inp);

        }
        if(s == "pop"){
            int g = order.front();       // 当前最靠前的小组
            int x = quenequ[g].front();
            quenequ[g].pop();
            cout << x << '\n';
            if (quenequ[g].empty()) {
                order.pop();             // 该小组已无元素，从全局移除
            }
        }
    }
    return 0;
}