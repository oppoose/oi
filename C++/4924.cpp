#include <iostream>
using namespace std;
int main()
{
    int n,m;
    int x,y,r,z;
    cin>>n>>m;

    int a[n][n];
    int temp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = (j+1)+n*i;
            temp[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        cin>>x>>y>>r>>z;
        x = x-1; y = y-1;
        if(z==0){
            for(int p = y-r; p <= y+r; p++){
                for(int k = x-r; k <= x+r; k++){
                    temp[p-y+x][x+y-k] = a[k][p];
                }
            }
            for(int p = y-r; p <= y+r; p++){
                for(int k = x-r; k <= x+r; k++){
                    a[p-y+x][x+y-k] = temp[p-y+x][x+y-k];
                    temp[p-y+x][x+y-k] = 0;
                }
            }
        }
        if(z==1){
            for(int p = y-r; p <= y+r; p++){
                for(int k = x-r; k <= x+r; k++){
                    temp[y+x-p][-x+y+k] = a[k][p];
                }
            }
            for(int p = y-r; p <= y+r; p++){
                for(int k = x-r; k <= x+r; k++){
                    a[y+x-p][-x+y+k] = temp[y+x-p][-x+y+k];
                    temp[y+x-p][-x+y+k] = 0;
                }
            }
        }
    }
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            cout<<a[i][j];
            if(j <= n-2) cout<<' ';
        }
        cout<<endl;
    }
}