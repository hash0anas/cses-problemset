#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
vector<vector<int>> adj(maxN);
vector<int> height(maxN); // height of each node, leaf = 1
vector<int> dist(maxN); // distance to its ancestor.

// The tree is unrooted, so it makes sense to define a leaf by having a degree of 1.
void dfs_height(int cur, int par) {
    for(int nei : adj[cur]) {
        if (nei != par) {
            dfs_height(nei, cur); // post-order .. natural when you wish to work with the leaves first.
            height[cur] = max(height[cur], height[nei]);
        }
    }
    height[cur]++;
}

void dfs_dist(int cur, int par) {
    // Distance is the max height of neighbors + 1, because, well, it makes sense.
    // First, get two neighbors (children) that have max heights.
    // Why do you need two neighbors? in case you happen to be processing the nei that has this max height,
    // you use the other one.
    int max_height1 = 0, max_height2 = 0;
    for(int nei : adj[cur]) {
        if(nei == par) continue;

        if(height[nei] >= max_height1) {
            max_height2 = max_height1;
            max_height1 = height[nei];
        }
        else if(height[nei] > max_height2) {
            max_height2 = height[nei];
        }
        else { /* Intentionally do nothing. */ }
    }

    // Now, find dist, as we defined it, in the pre-order of the dfs.
    for(int nei : adj[cur]) {
        if(nei == par) continue;

        if(height[nei] == max_height1) {
            dist[nei] = max(dist[cur], max_height2 + 1) + 1;
        }
        else {
            dist[nei] = max(dist[cur], max_height1 + 1) + 1;
        }
        dfs_dist(nei, cur);
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
    for(int i = 1; i <= n; ++i) {
        cout << max(dist[i], height[i]) - 1 << ' ';
    }
    cout << endl;
}
