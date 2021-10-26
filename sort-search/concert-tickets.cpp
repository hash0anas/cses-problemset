#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m;
    multiset<int> ms;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        ms.insert(x);
    }
    for(int i = 0; i < m; ++i) {
        cin >> x;
        // Find upper_bound of x;
        auto it = ms.upper_bound(x);
        if(it == ms.begin()) {
            cout << -1 << endl;
        }
        else {
            --it;
            cout << *it << endl;
            ms.erase(it);
        }
    }
}