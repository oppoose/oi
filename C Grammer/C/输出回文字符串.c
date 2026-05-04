int min(int a,int b){
    int t;
    if (a>b) t=b;
    else t=a;
    return t;
}

int max(int a,int b){
    int t;
    if (a>b) t=a;
    else t=b;
    return t;
}


int findmax (int s[],int length){
    int index = 0;
    for (int m=0;m<length;m++){
        if (s[m] > s[index]){
            index = m;
        }
    }
    return index;
}

char* longestPalindrome(char* s) {
    if (strlen(s)==1) return s;
    else{
    int cnt1[10000];
    int cnt2[10000];
    char *final;
    int max_cnt1 = 0;
    int max_cnt2 = 0;
    for(int k = 0;k<10000; k++){
        cnt1[k] = 0;
        cnt2[k] = 0;
    }
    //奇数
    //1234567890
    for(int i=0;i<strlen(s);i++){
        for(int j=0;j <= min(i,strlen(s)-i-1) ; j++){
            if (s[i-j] == s[i+j] ){
                cnt1[i]++;
            }
            else break;
        }
        max_cnt1 = max(max_cnt1,cnt1[i]);
    //偶数
        for(int j=0;j <= min(i,strlen(s)-i-1) ; j++){
            if (s[i-j] == s[i+j+1]){
                cnt2[i]++;
            }
            else break;
        }
        max_cnt2 = max(max_cnt2,cnt2[i]);
    }
    int a = findmax(cnt1,strlen(s));
    int b = findmax(cnt2,strlen(s));
    if (max_cnt1>=max_cnt2+1){
        int L = a - max_cnt1+1;
        int R = a + max_cnt1-1;
        int size = R-L+1;
//a0s1d2w3v4f5f6v7w8
//a0s1d2w3v4f5v6w7
//
        final = (char*)malloc(size+1); // +1 for '\0'
        strncpy(final, s+L, size);
        final[size] = '\0';
    }
    else{
        int L = b - max_cnt2+1;
        int R = b + max_cnt2;
        int size = R-L+1;

        final = (char*)malloc(size+1);
        strncpy(final, s+L, size);//s+L既是指针s(指向s[0]的)前移L，等价于s[L]
        final[size] = '\0';
        }
    return final;
    }
}
    
