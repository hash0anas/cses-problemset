#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6 + 5, MOD = 1e9 + 7;

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n), dp(sum+1);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    dp[0] = 1;
    // Just swap the order of the for-loops from coin-combinationI.
    // This way, we enforce processing the coins in one order.
    for(int coin : coins) {
       for(int x = 1; x <= sum; ++x) {
           if(x - coin >= 0) {
               dp[x] = (dp[x] + dp[x - coin]) % MOD;
           }
       } 
    }
    cout << dp[sum] << endl;
}