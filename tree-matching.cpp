#include <bits/stdc++.h>
using namespace std;

bool matched[200005];
vector<vector<int>> adj(200005);
int max_matching = 0;

void dfs_matching(int node, int parent) {
    for(int v : adj[node]) {
        if(v != parent) {
            dfs_matching(v, node);
        }
    }
    if(!matched[node] and !matched[parent] and parent != 0) {
        matched[node] = matched[parent] = true;
        ++max_matching;
    }
}
int main() {
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_matching(1, 0);
    cout << max_matching << endl;
}
