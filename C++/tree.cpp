#include <bits/stdc++.h>
using namespace std;
string a,b;
void deal(int l1,int r1,int l2,int r2){
    if(l1 > r1&&l2 > r2){return ;}
    //if(l1 == r1) {return ;}
    char root = b[r2];
    cout<<root;
    int pos = -1;
    for(int i = l1; i <= r1; i++){
        if(a[i] == root){
            pos = i;
            break;
        }
    }
    deal(l1 ,pos-1,l2,l2+pos-1-l1);
    deal(pos+1,r1,l2+pos-l1,r2-1);
}
int main(){
    //int n; cin>>n;
    cin>>a>>b;
    int l = a.length();
    deal(0,l-1,0,l-1);
}