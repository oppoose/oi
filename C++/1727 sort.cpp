#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int a, int b){

    return a > b;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),cmp);//使用STL中的sort函数进行排序
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }

}