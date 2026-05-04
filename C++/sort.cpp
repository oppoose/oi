#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int partition(vector<int>& a, int low, int high){
    int pi = rand()%(high - low + 1) + low;
    // swap(a[p], a[high]);//将随机选择的p放到最后
    // int p = a[high];//随机选择p
    int p = a[pi];
    int i = low - 1;//这里i指向小于p的最后一个元素
    for(int j = low; j < high; j++){
        if(a[j] < p){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i + 1;
}
void sort(vector<int>& a, int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        sort(a, low, pi - 1);
        sort(a, pi + 1, high);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a,0,n-1);
    for(int i = 0; i < n; i++){
        cout<<a[i];
    }
}