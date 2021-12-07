#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0; cin >> n;
    int ar[n];
    set<int> s;
    for(int i = 0; i < n; ++i) cin >> ar[i];
    for(int i = 0, j = 0; i < n; ++i) {
        while(j < n && !s.count(ar[j])) {
            s.insert(ar[j]);
            ++j;
        }
        s.erase(ar[i]);
        ans = max(ans, j - i);
    }
    cout << ans << endl;
}