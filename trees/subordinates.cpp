#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj, vector<int> &kids_count, int i = 1) {
    if(adj[i].size() == 0) {
        return 0;
    }
    int res = 0;
    for(int kid : adj[i]) {
        res += dfs(adj, kids_count, kid);
    }
    return kids_count[i] += res;
}
int main() {
    int n, e;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> kids_count(n+1);
    for(int i = 2; i <= n; ++i) {
        cin >> e;
        adj[e].push_back(i);
        kids_count[e]++;
    }
    for(int x : kids_count) cout << x << ' ';
    cout << endl;
}
