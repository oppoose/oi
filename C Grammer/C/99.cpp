#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i,j,n;
    cin>>std::hex>>n;

    for(j=1;j<n+1;j++){
        for(i=1;i<=j;i++){
            cout<<j<<"x"<<i<<"="<<i*j;
            if (i!=j){
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    //printf("%d",sizeof(i));
    return 0;
}