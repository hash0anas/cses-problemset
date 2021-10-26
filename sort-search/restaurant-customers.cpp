#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    pair<int, int> ar[2*n];
    for(int i = 0; i < 2*n; i += 2) {
        cin >> a >> b;
        ar[i] = make_pair(a, 1);
        ar[i+1] = make_pair(b, -1);
    }
    sort(ar, ar+(2*n));
    int max_all_time = 0, current_max = 0;
    for(auto p : ar) {
        current_max += p.second;
        max_all_time = max(max_all_time, current_max);
    }
    cout << max_all_time << endl;
}