#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <random>
#include <string>
#include <sstream>
using namespace std;

vector<int> bc;
vector<vector<pair<int, int>>> ll; // 替代 ArrayList<xx>

// 预处理计算l数组
vector<int> precompute() {
    vector<int> l(1000001, 0);
    l[1] = 1;
    
    for (long long a = 2; a <= 1000000; a++) {
        for (long long r = 2; r * r * a <= 1000000; r++) {
            long long d = a * a * r * r * r * r - 4 * (a * a - r * r);
            long long o = (long long)sqrt(d);
            
            if (o * o != d) continue;
            
            if (o >= 0) {
                if ((o + a * r * r) % 2 == 0 && (o + a * r * r) / 2 <= 1000000) {
                    l[max((long long)a, (o + a * r * r) / 2)] += 2;
                }
            }
        }
    }
    
    for (int i = 2; i <= 1000000; i++) {
        l[i] += l[i - 1];
    }
    
    return l;
}

// 并查集查找
int fd(int x) {
    return bc[x] == x ? x : (bc[x] = fd(bc[x]));
}

// 初始化并查集
void fb(int n) {
    bc.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        bc[i] = i;
    }
}

// 最大公约数
long long gcd(long long a, long long b) {
    return b > 0 ? gcd(b, a % b) : a;
}

// 快速幂
long long ksm(long long a, long long b) {
    long long sum = 1;
    while (b > 0) {
        if (b % 2 == 1) sum = sum * a;
        a = a * a;
        b = b / 2;
    }
    return sum;
}

// 写入文件
// void solve(const string& ss) {
//     string filePath = "C:\\Users\\15871\\Desktop\\out01.txt";
//     ofstream writer(filePath);
//     if (writer.is_open()) {
//         writer << ss;
//         writer.close();
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 预处理l数组
    vector<int> l = precompute();
    
    int n;
    while (cin >> n) {
        stringstream ss;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ss << l[x] << "\n";
        }
        string result = ss.str();
        cout << result;
        solve(result);
    }
    
    return 0;
}

