#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while(n >= 5) {
        ans += (n / 5);
        n /= 5;
    }
    cout << ans << endl;
}