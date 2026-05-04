#include <bits/stdc++.h>
using namespace std;

const int mod = 10000;

int main(){

    int x,s = 0,t = 0; //x是当前的数，s是和，t是当前段的乘积
    char c;

    scanf("%d",&t);
    while(scanf("%c",&c) && c != '\n'){
        scanf("%d",&x);
        if(c == '*') t = t * x % mod; //是乘号就相乘
        else s = (s + t) % mod,t = x;
            
    }
    printf("%d\n",(s + t) % mod);
        return 0;
}




//你的想法是先算乘法后算加法,想先find*,后来才想从左到右,但是第一个是加法怎么办

//这个是直接流式处理,加法右边直接变成乘法左边对象