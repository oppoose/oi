#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50010;

int n, k;
int fa[MAXN];   // 父节点
int d[MAXN];    // 到父节点的关系（mod 3）

// 查找 + 路径压缩
int find(int x) {
    if (fa[x] != x) {
        int root = find(fa[x]);
        d[x] += d[fa[x]];   // 关键：维护到根的关系
        d[x] %= 3;
        fa[x] = root;
    }
    return fa[x];
}

int main() {
    cin >> n >> k;

    // 初始化
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        d[i] = 0;  // 自己到自己差值为0
    }

    int ans = 0;

    while (k--) {
        int op, x, y;
        cin >> op >> x >> y;

        // 越界直接是假话
        if (x > n || y > n) {
            ans++;
            continue;
        }

        int fx = find(x);
        int fy = find(y);

        if (fx == fy) {
            // 已在同一集合，检查是否矛盾
            if (op == 1) {
                // 同类：差值应该是0
                if ((d[x] - d[y]) % 3 != 0) ans++;
            } else {
                // x吃y：差值应该是1
                if ((d[x] - d[y] - 1) % 3 != 0) ans++;
            }
        } else {
            // 不在同一集合，合并
            fa[fx] = fy;

            if (op == 1) {
                // d[fx] = d[y] - d[x]
                d[fx] = d[y] - d[x];
            } else {
                // d[fx] = d[y] - d[x] + 1
                d[fx] = d[y] - d[x] + 1;
            }

            d[fx] %= 3;
            if (d[fx] < 0) d[fx] += 3;  // 防止负数
        }
    }

    cout << ans << endl;
    return 0;
}