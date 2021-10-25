#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pi;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k, u;
        cin >> n;
        vector<vector<int>> adj(n+1);
        vector<int> in_degree(n+1);
        for(int i = 1; i <= n; ++i) {
            cin >> k;
            for(int j = 1; j <= k; ++j) {
                cin >> u;
                adj[u].push_back(i);
                in_degree[i]++;
            }
        }
            
        // Now, let's do toplogical sorting with a priority for early chapters.
        // Assume for now it's a dag.
        priority_queue<pi, vector<pi>, greater<pi>> pq; //min pq.
        for(int u = 1; u <= n; ++u) {
            if(in_degree[u] == 0) pq.emplace(u, 1);
        }
        int ans = 0;
        while(!pq.empty()) {
            pi cur = pq.top();
            pq.pop();
            int chapter = cur.first, reads = cur.second;
            ans = max(ans, reads);
            for(int v : adj[chapter]) {
                in_degree[v]--;
                if(in_degree[v] == 0) {
                    int vreads = reads;
                    if(chapter > v) vreads++;
                    pq.push(make_pair(v, vreads));
                }
            }
        } 
        bool finished = true;
        for(int i = 1; i <= n; ++i) {
            if(in_degree[i] > 0) {
                finished = false;
                break;
            }
        }
        cout << (finished ? ans : -1) << endl;
    }
} 