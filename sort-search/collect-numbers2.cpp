#include <bits/stdc++.h>
using namespace std;

// Does NOT work, problem statement is stupidly unclear.

int main() {
    int n, m, r = 0;
    cin >> n >> m;
    vector<int> v(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
        r += (v[i] < v[i-1]);
    }
    int a, b, r2;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        r2 = r;
        if(v[a] < v[a+1] && v[b] > v[a+1]) ++r2;
        if(v[b] > v[b-1] && v[a] < v[b-1]) ++r2;

        if(v[a] > v[a+1] && v[b] < v[a+1]) --r2;
        if(v[b] < v[b-1] && v[a] > v[b-1]) --r2;

        swap(v[a], v[b]);
        cout << r2 << endl;
    }
}