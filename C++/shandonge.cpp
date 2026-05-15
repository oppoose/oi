#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int g, int n, int k, int mx, int S, const vector<int>& pcnt,
           const vector<int>& psum) {
  if (g > mx) {
    int need = n * g - S;
    return need <= k;
  }

  int need = 0;

  for (int L = 1; L <= mx; L += g) {
    int R = min(mx, L + g - 1);

    int c = pcnt[R] - pcnt[L - 1];
    int s = psum[R] - psum[L - 1];

    int to = ((L + g - 1) / g) * g;

    need += to * c - s;

    if (need > k) return false;
  }

  return need <= k;
}

void so() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n + 1);

  int suma = 0;
  int maxa = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    suma += a[i];
    maxa = max(maxa, a[i]);
  }

  vector<int> tong(maxa + 1, 0);
  vector<int> sum(maxa + 1, 0);

  for (int i = 1; i <= n; ++i) {
    tong[a[i]]++;
    sum[a[i]] += a[i];
  }

  vector<int> ptong(maxa + 1, 0);
  vector<int> psum(maxa + 1, 0);

  for (int i = 1; i <= maxa; ++i) {
    ptong[i] = ptong[i - 1] + tong[i];
    psum[i] = psum[i - 1] + sum[i];
  }

  int M = suma + k;

  vector<int> divs;

  for (int i = 1; i * i <= M; ++i) {
    if (M % i == 0) {
      divs.push_back(i);

      if (i * i != M) divs.push_back(M / i);
    }
  }

  sort(divs.rbegin(), divs.rend());

  for (int g : divs) {
    if (g > M / n) continue;

    if (check(g, n, k, maxa, suma, ptong, psum)) {
      cout << g << '\n';
      return;
    }
  }

  cout << 1 << '\n';
}

#undef int

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    so();
  }

  return 0;
}