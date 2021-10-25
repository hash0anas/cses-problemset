#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m, a, b, c; cin >> n >> m;
        vector<pair<int,int>> ans;
        vector<bool> conn (n+1);
        set<int> bs;
        for(int i = 0; i < m; ++i) {
            cin >> a >> b >> c;
            ans.emplace_back(a, c);
            bs.push_back(b);
            conn[a] = conn[c] = true;
        }
        int edges = m;
        while (edges <= n - 1) {
            for(int b : bs) {
                ans.empalce_back(a, b)
                edges++;
            }
        }
        for(int i = )
    }
}