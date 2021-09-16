#include <iostream>

using namespace std;

const unsigned int MOD = (1e9 + 7);

long long two_power(int n) {
    long long ans = 1;
    while(n--) {
        ans *= 2;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    long long ans = 1;
    while(n > 0) {
        int power = (n >= 30 ? 30 : n);
        n -= 30;
        ans *= (two_power(power) % MOD);
        ans %= MOD;
    }
    cout << ans << endl;
}