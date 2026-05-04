#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> p(n);
    vector<long long> a(n);
    vector<long long> suma(n,0);
    for(int i = 0; i < n; i++){
        cin>>p[i];
    }
    long long sum = 0;
    cin>>a[0];
    suma[0] = a[0];
    for(int i = 1; i < n; i++){
        cin>>a[i];
        suma[i] = suma[i-1] + a[i];//前缀和,不是自增
    }
    for(int i = 0; i < n; i++){
        sum += a[i]*(p[i]-p[0]);
    }
    
    int maxp = 1;
    long long minm = sum;
    for(int i = 0; i < n - 1; i++){
        sum += -2*a[i+1]*p[i+1] - suma[i]*p[i] + suma[i+1]*p[i+1] +p[i]*(suma[n-1]-suma[i]) - p[i+1]*(suma[n-1]-suma[i+1]);
        //每次移动一个点,更新sum

        if(sum < minm){
            maxp = i + 2;
            minm = min(minm,sum);
        }
    }
    cout << maxp;

    
}




//