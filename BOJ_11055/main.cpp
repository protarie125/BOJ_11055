#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n;
vl A;
vl dp;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;

  A = vl(n + 1);
  for (auto i = 1; i <= n; ++i) {
    cin >> A[i];
  }

  auto ans = ll{0};
  dp = vl(n + 1, 0);
  for (auto i = 1; i <= n; ++i) {
    dp[i] = A[i];
    for (auto j = 1; j < i; ++j) {
      if (A[j] < A[i]) {
        dp[i] = max(dp[i], dp[j] + A[i]);
      }
    }
    ans = max(ans, dp[i]);
  }

  cout << ans;

  return 0;
}