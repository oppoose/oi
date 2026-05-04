#include <bits/stdc++.h>
using namespace std;
int r[10][10],c[10][10];
int s[10][10];
int l[10][10];
int flag[10][10];
int main(){
    int x;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            flag[i][j] = (j/3 + 1) + 3*(i/3 + 1);
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin>>x;
            r[j][x] = 1;
            l[x][i] = 1;
            s[flag[i][j]][x] = 1;
        }
    }
}