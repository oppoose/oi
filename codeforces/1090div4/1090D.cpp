#include <bits/stdc++.h>
using namespace std;

const int MAXP = 200000;
vector<int> primes;

void sieve() {
    vector<bool> is_prime(MAXP + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAXP; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = (long long)i * i; j <= MAXP; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << "2 2\n";
            continue;
        }
        vector<long long> a(n);
        a[0] = primes[0];                     // p1
        for (int i = 1; i < n - 1; ++i) {
            a[i] = (long long)primes[i-1] * primes[i]; // p_{i-1} * p_i
        }
        a[n-1] = primes[n-2];                 // p_{n-1}
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " \n"[i == n-1];
        }
    }
    return 0;
}