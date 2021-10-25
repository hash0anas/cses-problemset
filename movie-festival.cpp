#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<pair<int,int>> time(n);
    for(int i = 0; i < n; ++i) {
        cin >> time[i].first >> time[i].second;
    }
    // sort by ending time
    sort(time.begin(), time.end(), [](auto p1, auto p2) {
        return p1.second < p2.second;
    });
    int ans = 1, last_watched = 0;
    for(int i = 1; i < n; ++i) {
        if (time[i].first >= time[last_watched].second) {
            last_watched = i;
            ans++;
        }
    }
    cout << ans << endl;
}