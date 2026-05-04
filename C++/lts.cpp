#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& a) {
    vector<int> d; // d[i] = 长度为 i+1 的 LIS 最小结尾

    for (int x : a) {
        auto it = lower_bound(d.begin(), d.end(), x);
        
        if (it == d.end()) {
            d.push_back(x);  // 扩展
        } else {
            *it = x;         // 替换
        }
    }

    return d.size();
}

int main() {
    vector<int> a = {3, 5, 7, 1, 2, 8};
    cout << LIS(a) << endl; // 输出 4
}