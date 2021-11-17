#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    sort(begin(v), end(v));

    long long ans = 1;
    for(int i = 0; i < n && v[i] <= ans; ++i) ans += v[i];
    cout << ans << endl;
}