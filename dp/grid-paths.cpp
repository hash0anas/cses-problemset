#include <bits/stdc++.h>
using namespace std;

const int mxN = 10005, MOD = 1e9 + 7;
int n;
string grid[mxN];
int dp[mxN][mxN];

// Now, this was your top-down dp.
// Give me your bottom-up.

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  int dp[n][n];
  memset(dp, 0, n * sizeof(dp[0]));
  dp[0][0] = (grid[0][0] == '.');

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '.') {
        if (i > 0)
          dp[i][j] += dp[i - 1][j];
        if (j > 0)
          dp[i][j] += dp[i][j - 1];
      }
      dp[i][j] %= MOD;
    }
  }
  if (grid[n - 1][n - 1] == '*')
    dp[n - 1][n - 1] = 0;
  cout << dp[n - 1][n - 1] << endl;
}

