#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mo = 676767677;
void so() {
  int n;
  cin >> n;
  vector<int> a(n + 10, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  int i = 0;
  while (i <= n) {
    int ans = 1;
    while (a[i] == 1 && i <= n) {
        i++;
    }
    ans = a[i];
    if(i == n+1){
        ans = 1;
    }
    sum += ans;
    sum %= mo;
    i++;
  }
  cout << sum << endl;
}
#undef int
int main() {
  int t;
  cin >> t;
  while (t--) {
    so();
  }
}