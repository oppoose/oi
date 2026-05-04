#include <bits/stdc++.h>
using namespace std;
int map[10][10];//地图
int a[10][10];//哪些点不能再走了记录在此
int dis[10][10];//每个点的距离
struct ty {
    int x;
    int y;

    // 这里重载 operator<，让 priority_queue 按 dist 从小到大排序
    bool operator<(const ty& other) const {
        return x > other.x;
    }
};
queue<pair<int,int>> b;
void illegal(pair<int,int> a){
    
}

void bfs(int x,int y){
    pair<int,int> point = {x,y};
    if(b.empty()){
        b.push(point);
    }
    while(!b.empty()){
        pair<int,int> item = b.front();
        int x = item.first;
        int y = item.second;
        illegal(item);
    }
}
int main(){
    for(int i =0; i < 9; i++){
        for(int j = 0; j < 9; j++){

        }
    }
}