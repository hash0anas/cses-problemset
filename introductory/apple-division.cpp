#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[20];
bool vis[20];

ll rec(int i = 0) {
    if(i == n) {
        ll g1 = 0, g2 = 0;
        for(int j = 0; j < n; ++j) {
            if (vis[j]) g1 += a[j];
            else g2 += a[j];
        }
        return abs(g1 - g2);
    }
    vis[i] = true;
    ll rec1 = rec(i + 1);

    vis[i] = false; // BT.
    ll rec2 = rec(i + 1);

    return min(rec1, rec2);
}
int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << rec() << endl;
}