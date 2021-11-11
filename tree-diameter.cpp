#include <bits/stdc++.h>
using namespace std;

int bfs_furthest_node(vector<vector<int>> &adj, int u) {
    // shimple, use a queue.
    queue<int> q; q.push(u);
    vector<bool> vis(adj.size()+1); vis[u] = true;
    int furthest_node = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        vis[cur] = true;
        for(int v : adj[cur]) {
            if(!vis[v])
                q.push(v);
        }
        furthest_node = cur;
    }
    return furthest_node;
}

int bfs_path(vector<vector<int>> &adj, int s, int t) {
    if(s == t) return 0;

    queue<int> q; q.push(s);
    vector<bool> vis(adj.size()+1); vis[s] = true;
    int dist = 1;

    while(!q.empty()) {
        int level_width = q.size();
        for(int i = 0; i < level_width; ++i) {
            int cur = q.front(); q.pop();
            for(int v : adj[cur]) {
                if(v == t) return dist;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        ++dist;
    }
    return dist;
}

int main() {
    int n, a, b;
    cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        exit(0);
    }
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // So, finding the diameter, the greedy algorithm is:
    // Pick any node, BFS from there to find the furthest node to it.
    int s = bfs_furthest_node(adj, 1);
    // Now, find the furthest node to t :)
    int t = bfs_furthest_node(adj, s);

    // Now, we want to find the path length between s-t, this is the diameter.
    cout << bfs_path(adj, s, t) << endl;
}