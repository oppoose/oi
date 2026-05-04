#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 10][m + 10] = {0};

    int pos[n + 10][m + 10];
    for (int i = 1; i <= n; ++i)
    {
        a[i][0] = 0;
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            pos[i][j] = a[i][j] - a[i][j - 1];
        }
    }
    int q;
    cin >> q; // 对区间a[l,r]加d
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j <= y2; j++)
        {
            pos[x1][j] += 1;
            pos[x2 + 1][j] -= 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = a[i][j - 1] + p[i][j];
        }
    }
    long long sum ;
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m; j++){
            sum += (i+j)^a[i][j];
        }
    }
    return 0;
}