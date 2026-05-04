#include <bits/stdc++.h>
using namespace std;
void qsort(vector<int> &a,int l,int r){
    //if(l == r) return ;
    int mid = (l+r)/2;
    int x = a[mid];
    int i = l, j = r;
    while(i <= j){
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j) {
            swap(a[i],a[j]);i++;j--;
        }
    }
    if(l < j) qsort(a,l,j);
    if(i < r) qsort(a,i,r);

}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    qsort(a,0,n-1);
    for(int i = 0; i < n; i++){
        cout<<a[i];
    }
}