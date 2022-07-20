// Your classic knapsack.
// DP it bottom-up, aka tabulation.
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> costs(n), values(n);
    for(int i = 0; i < n; ++i) {
        cin >> costs[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    vector<int> dp(x+1);
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = x; j >= 0; --j) {
 
            if(j >= costs[i-1]) { // can buy this book.
                dp[j] = max(dp[j], dp[j-costs[i-1]] + values[i-1]);
            }
            ans = max(ans, dp[j]);
        }
    }
 
    cout << ans << endl;
}
