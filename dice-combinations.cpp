#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= min(6, i); ++j) {
            d[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n] << endl;
}