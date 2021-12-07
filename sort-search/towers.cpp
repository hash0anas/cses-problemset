#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    multiset<int> s;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        cin >> k;
        auto it = s.upper_bound(k);
        if(it == s.end()) ++ans;
        else s.erase(it);
        s.insert(k);
    }
    cout << ans << '\n';
}