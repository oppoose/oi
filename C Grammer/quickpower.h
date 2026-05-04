#define smell 100000000
#ifndef quickpower_h
#define quickpower_h

long long i_k (long long i,long long k){
    long long ans = 1;
    if(i==1) return 1;
    if(k==1) return i;
    while(k>1){
        if(k&1){
            ans = (ans * i)%smell;
            k -= 1;
        }
            i = (i*i)%smell;
            k /= 2;
    }
    return (ans*i)%smell;
}
#endif