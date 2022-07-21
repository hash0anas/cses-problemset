#include <bits/stdc++.h>
using namespace std;

int a[200005], pos[200005];

int main() {
    int n, q;
    cin >> n >> q;
    int rounds = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
        rounds += (pos[a[i] - 1] == 0); // Haven't seen a[i] - 1? Another round.
    }
    set<pair<int, int>> updates;
    int i, j;
    while(q--) {
        cin >> i >> j;
        // inversions to consider ...
        if(a[i] + 1 <= n) updates.insert(make_pair(a[i], a[i] + 1));
        if(a[i] - 1 >= 1) updates.insert(make_pair(a[i] - 1, a[i]));
        if(a[j] + 1 <= n) updates.insert(make_pair(a[j], a[j] + 1));
        if(a[j] - 1 >= 1) updates.insert(make_pair(a[j] - 1, a[j]));

        for(auto [st, nd] : updates) {
            rounds -= pos[st] > pos[nd];
        }

        swap(a[i], a[j]);
        pos[a[i]] = i;
        pos[a[j]] = j;

        for(auto [st, nd] : updates) {
            rounds += pos[st] > pos[nd];
        }
        cout << rounds << endl;
        updates.clear();
    }
}
