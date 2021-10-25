#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> vis;

void dfs(string cur) {
    vis[stoi(cur, 0, 2)] = true;
    cout << cur << endl;
    for(int i = n - 1; i >= 0; --i) {
        cur[i] = cur[i] ^ 1; // invert the bit at i.
        if(!vis[stoi(cur, 0, 2)]) {
            dfs(cur);
        }
        cur[i] = cur[i] ^ 1; // invert the same bit back.
    }
}

int main() {
    cin >> n;
    vis = vector<bool>(1 << n);
    dfs(string(n, '0'));
}
