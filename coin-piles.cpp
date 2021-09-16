#include <bits/stdc++.h>

using namespace std;

bool is_power2(int n) {
    return ceil(log2(n)) == floor(log2(n));
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int a, b;
        cin >> a >> b;
        bool ok = true;
        if(a == 1 && b == 2 || a == 2 && b == 1) {
            cout << "YES\n";
            continue;
        }
        if(abs(a - b) > min(a, b) || (is_power2(a) && is_power2(b))) ok = false;
        // if(is_power2(a) && is_power2(b)) ok = false;

        cout << (ok ? "YES" : "NO") << endl;
    }
}