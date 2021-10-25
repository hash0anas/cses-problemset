#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int app[n], apt[m];
    for(int i = 0; i < n; ++i) cin >> app[i];
    for(int i = 0; i < m; ++i) cin >> apt[i];
    sort(app, app + n);
    sort(apt, apt + m);
    
    int ans = 0;
    for(int i = 0, j = 0; i < n && j < m;) {
        if(app[i] >= apt[j] - k && app[i] <= apt[j] + k) {
            ++ans; 
            ++i; ++j;
        }
        else if(app[i] >= apt[j] - k) {
            ++j;
        }
        else if(app[i] <= apt[j] + k) {
            ++i;
        } 
    }
    cout << ans << endl;
}