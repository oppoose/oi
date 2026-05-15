// #include <bits/stdc++.h>
// using namespace std;
// int cnt(long long x){
//     int sum = 0;
//     while(x > 0){
//         sum+=(x%10);
//         x = x/10;
//     }
//     return sum;
// }

// int main(){
//     int num = 1;
//     int cnt0;
//     cout <<"query "<<0<<endl;;
//     cin>> cnt0;
//     fflush(stdout);
//     int sum = 0;
//     int flag = 0;
//     while(1){
//         int l = 1, r = 10;
//         while(l <= r){
//             int mid = (l+r)/2;
//             cout <<"query "<<mid*num<<endl;
//             int x;
//             cin>>x;
//             fflush(stdout);
//             if(x - cnt0 == mid){
//                 l = mid + 1;
//                 if(l == 10){
//                     flag = 1;
//                     break;
//                 }
//             }
//             else r = mid  - 1;
//         }
//         if(flag == 1) break;
//         sum += (10-l)*num;
//         num *= 10;
//     }
//     cout<<"answer "<<sum;
// }



#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

ull pow10[19]; // 10^0 .. 10^18

void init() {
    pow10[0] = 1;
    for (int i = 1; i <= 18; ++i)
        pow10[i] = pow10[i - 1] * 10;
}

int query(ull a) {
    cout << "query " << a << endl;
    int res;
    cin >> res;
    return res;
}

int digit_sum(ull x) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    init();
    int S0 = query(0);
    if (S0 == 0) {
        cout << "answer 0" << endl;
        return 0;
    }

    ull offset = 0;
    int S_cur = S0;

    // 处理低 17 位 (i = 0 .. 16)
    for (int i = 0; i <= 16; ++i) {
        int lo = 1, hi = 11;          // 需要测试的 k 范围 [1, 10]
        int res_ans = -1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int res = query(offset + mid * pow10[i]);
            if (res < S_cur + mid) {  // 发生进位
                hi = mid;
                res_ans = res;
            } else {
                lo = mid + 1;
            }
        }
        int k = lo;                    // 使该位清零所需的最小进位 k
        offset += k * pow10[i];
        S_cur = res_ans;              // 更新当前数位和
    }

    // 此时 x + offset = M * 10^17
    // 枚举可能的 M，满足 digit_sum(M) == S_cur 且 x 在范围内
    vector<ull> candidates;
    for (int M = 0; M <= 20; ++M) {
        if (digit_sum(M) != S_cur) continue;
        ull x = M * pow10[17] - offset;
        if (x < pow10[18]) {          // x < 10^18
            candidates.push_back(x);
        }
    }

    ull answer_x;
    if (candidates.size() == 1) {
        answer_x = candidates[0];
    } else {
        // 存在歧义 (只有 S_cur=1 或 2 时可能)，通过查询 a=1 区分
        int res1 = query(1);
        for (ull x : candidates) {
            if (digit_sum(x + 1) == res1) {
                answer_x = x;
                break;
            }
        }
    }

    cout << "answer " << answer_x << endl;
    return 0;
}