#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> moves;

void solve(int k, int l, int r, int m) {
    if (k <= 1) {
        moves.emplace_back(l, r);
        return;
    }
    
    solve(k - 1, l, m, r);
    moves.emplace_back(l, r); // move kth disk from l to r.
    solve(k - 1, m, r, l);
} 
int main() {
    cin >> n;
    solve(n, 1, 3, 2);
    cout << moves.size() << endl;
    for(auto p : moves) cout << p.first << ' ' << p.second << endl;
}