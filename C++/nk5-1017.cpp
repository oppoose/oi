#include <bits/stdc++.h>
using namespace std;
struct ty{
    int x,y;
    bool operator < (const ty &a,const ty &b){
        return (a.x < b.x) ||(a.x <= b.x) && (a.y < b.y)
    }
}
int main(){
    int n;cin>>n;

}