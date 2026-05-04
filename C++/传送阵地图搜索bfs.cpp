// #include <bits/stdc++.h>
// using namespace std;
// int maps[400][400];//地图
// int vis[400][400] = {0};//走过了吗?
// int dir[4][2]={ {1,0} ,{-1,0} ,{0,1} ,{0,-1} };

// struct ty{
//     int x;
//     int y;
//     int dis;
// }a[400][400];
// ty cs[400][400];

// struct comp{
//     bool operator()(ty &a, ty &b){
//         return a.dis<b.dis;
//     }
// };

// priority_queue<ty,vector<ty>,comp> b;

// int bfs(ty s,ty t){
//     if(b.empty()){
//         b.push(s);
//     }
//     while(!b.empty()){
//         ty item = b.top();
//         b.pop();
        
//         int x = item.x;
//         int y = item.y;
//         if(x==t.x&&y==t.y) return t.dis;
//         int disa = item.dis;
//         for(int i = 0; i < 4; i++){
//             int dx = x + dir[i][0];
//             int dy = y + dir[i][1];
//             if((maps[dx][dy] != -1) && vis[dx][dy] == 0){
//                 b.push({dx,dy,disa+1});
//                 vis[dx][dy] = 1;
//                 a[dx][dy].x = dx;
//                 a[dx][dy].y = dy;
//                 a[dx][dy].dis = disa + 1;
//             }
//             if(cs[dx][dy].dis == 0){
//                 int disb = a[dx][dy].dis;
//                 int ddx = cs[dx][dy].x;
//                 int ddy = cs[dx][dy].y;
//                 b.push({ddx,ddy,disb + 3});
//                 a[ddx][ddy].x = ddx;
//                 a[ddx][ddy].y = ddy;
//                 a[ddx][ddy].dis = disb + 3;
//             }
//         }
//     }
// }
// int main(){
//     memset(maps,-1,sizeof(maps));
//     memset(a,-1,sizeof(a));
//     int n,m,q;
//     while(cin>>n>>m>>q){
//         ty start;
//         ty target;
//         for(int i =1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 char x;cin>>x;
//                 cs.[i][j].dis = -1;
//                 if(x == '.')maps[i][j] = 0;
//                 if(x == '#')maps[i][j] = -1;
//                 if(x == 'S'){
//                     maps[i][j] = 0;
//                     start.x = i;
//                     start.y = j;
//                 }
//                 if(x == 'T'){
//                     maps[i][j] = 0;
//                     target.x = i;
//                     target.y = j;
//                 }
//             }
//         }
//         int x1,y1;
//         for(int i = 0; i < q; i++){
//             cin>>x1>>y1;
//             cin>>cs[x1][y1].x>>cs[x1][y1].y;
//             cs[x1][y1].dis = 0;
//         }
//         bfs(start,target);
//         cout<<target.dis;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int maps[400][400]; // 地图
int vis[400][400] = {0}; // 走过了吗?
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

struct ty {
    int x;
    int y;
    int dis;
} a[400][400];

struct cs_ty {
    int x;
    int y;
    int dis;
};

vector<cs_ty> cs[400][400]; // 改为 vector 支持多入口

struct comp {
    bool operator()(const ty &a, const ty &b) const { // 加 const 规范
        return a.dis > b.dis;
    }
};

priority_queue<ty, vector<ty>, comp> b;

int bfs(ty s, ty t) {
    while (!b.empty()) b.pop();
    memset(vis, 0, sizeof(vis));

    b.push(s);
    // 不再在这里标记 vis[s.x][s.y] = 1;

    while (!b.empty()) {
        ty item = b.top();
        b.pop();

        int x = item.x;
        int y = item.y;
        int disa = item.dis;

        // 出队时检查是否已访问过（Dijkstra 正确标记）
        if (vis[x][y]) continue;
        vis[x][y] = 1;

        if (x == t.x && y == t.y) return disa;

        // 处理传送阵（当前位置可能有多个）
        for (auto &c : cs[x][y]) {
            if (c.dis == 0) { // 有传送阵
                int ddx = c.x;
                int ddy = c.y;
                if (maps[ddx][ddy] != -1) {
                    b.push({ddx, ddy, disa + 3});
                    // 不在这里标记 vis
                }
            }
        }

        // 四个方向移动
        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (maps[dx][dy] != -1) {
                b.push({dx, dy, disa + 1});
                // 不在这里标记 vis
            }
        }
    }
    return -1;
}

int main() {
    memset(maps, -1, sizeof(maps));
    memset(a, -1, sizeof(a));

    int n, m, q;
    while (cin >> n >> m >> q) {
        ty start;
        ty target;
        start.dis = 0;

        // 清空传送阵 vector
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cs[i][j].clear();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char x;
                cin >> x;
                if (x == '.') maps[i][j] = 0;
                if (x == '#') maps[i][j] = -1;
                if (x == 'S') {
                    maps[i][j] = 0;
                    start.x = i;
                    start.y = j;   // 修正 y 坐标
                }
                if (x == 'T') {
                    maps[i][j] = 0;
                    target.x = i;
                    target.y = j;
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            // 坐标从 0 开始，转为 1-based
            cs_ty tmp;
            tmp.x = x2 + 1;
            tmp.y = y2 + 1;
            tmp.dis = 0;
            cs[x1 + 1][y1 + 1].push_back(tmp);
        }

        cout << bfs(start, target) << endl;
    }
    return 0;
}