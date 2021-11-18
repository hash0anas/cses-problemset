#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6 + 5;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n), dp(x+1);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    dp[0] = 0;
    for(int i = 1; i <= x; ++i) {
        dp[i] = INF;
        for(int coin : coins) {
            if(coin <= i)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    cout << (dp[x] > x ? -1 : dp[x]) << endl; // min coin = 1, so dp[x] <= x for valid solutions.
}
