#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int tt, x, y;
    cin >> tt;
    while(tt--) {
        cin >> x >> y;
        ll m = max(x, y);
        ll distance = abs(x - m) + abs(y - m);
        ll middle_value = m * m - m + 1; // value at (m, m).
                
        if ((m == y) != (m & 1)) distance *= -1;
        cout << middle_value + distance << endl;
    }
}