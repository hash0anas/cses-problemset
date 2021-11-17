#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    sort(v.begin(), v.end());

    int median = v[n / 2]; // median-ish.
    ll cost = 0;
    for(int &x : v) cost += abs(x - median);
    cout << cost << endl;
}