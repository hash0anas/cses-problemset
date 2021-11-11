#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

const int maxN = 200005;
int height[maxN]; // height of each node, post-order dfs, leaf = 1.
// height of a node is the max distance to a node in its subtree.

int dist[maxN]; // dist of a node is the max distance to a node in all its ancestors.
vvi adj(maxN);

void dfs_height(int u, int p) { // u is current, p is parent.
    for(int v : adj[u]) {
        if(v != p) {
            dfs_height(v, u);
            height[u] = max(height[u], height[v]);
        }
    }
    height[u]++;
}

void dfs_dist(int u, int p) {
    // get two neighbors with max height.
    int max_height1 = 0, max_height2 = 0;
    for(int v : adj[u]) {
        if(v != p) {
            if(height[v] >= max_height1) {
                max_height2 = max_height1;
                max_height1 = height[v];
            }
            else if(height[v] > max_height2) {
                max_height2 = height[v];
            }
            else { } // Do nothing.
        }
    }

    for(int v : adj[u]) {
        if(v != p) {
            if(height[v] == max_height1) {
                dist[v] = max(dist[u], 1 + max_height2) + 1;
            }
            else {
                dist[v] = max(dist[u], 1 + max_height1) + 1;
            }

            dfs_dist(v, u);
        }
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
    dfs_height(1, 0);
    dfs_dist(1, 0);
    // for each node, answer is the max of the two distances.
    for(int i = 1; i <= n; ++i) {
        cout << max(height[i], dist[i]) - 1 << ' ';
    }
    cout << endl;
}