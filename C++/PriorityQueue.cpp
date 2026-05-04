#include <iostream>
#include <string>
#include <queue>
#include <cctype> 
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);//这句的意思是将cin和cout的同步关闭，以提高输入输出效率。默认情况下，cin和cout是同步的，这意味着它们会在每次输入输出操作后刷新缓冲区，这可能会导致性能下降。通过调用cin.tie(nullptr)，我们可以将cin与cout解绑，使得它们不再相互影响，从而提高输入输出的效率。这在处理大量数据时尤其有用，可以显著减少程序的运行时间。


    priority_queue<int> m;
    string s;
    int n;
    while(cin>>s && s != "end"){
        if(s == "insert"){
            cin>>n;
            m.push(n);
        }
        if(s == "extract"){
            cout<<m.top()<<"\n";
            m.pop();
        }
    }
    return 0;
}