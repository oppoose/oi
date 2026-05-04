#include <iostream>
using namespace std;
int main()
{
    int currVal = 0;
    int val = 0;
    int cnt = 0;
    if(cin>>val){
        cnt = 1;
    }
    while(cin>>currVal){
        if(currVal == val){
            ++cnt;
        }
        else{
            cout<<val<<"出现了"
            <<cnt<<"次"<<endl;
            val = currVal;
            cnt = 1;
        }
        
    }
    cout<<val<<"出现了"
    <<cnt<<"次"<<endl;
    return 0;
}