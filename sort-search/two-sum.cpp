#include <bits/stdc++.h>
using namespace std;

// O(n log n) solution. O(1) space;
/*
int main() {
    int n, x; cin >> n >> x;
    pair<int, int> ar[n];
    for(int i = 0; i < n; ++i) {
        cin >> ar[i].first;
        ar[i].second = i;
    } 
    sort(ar, ar+n);

    int i = 0, j = n - 1;
    while(i < j) {
        int sum = ar[i].first + ar[j].first;
        if(sum == x) {
            int ari = ar[i].second, arj = ar[j].second;
            if(ari > arj) swap(ari, arj);
            cout << (ari+1) << ' ' << (arj+1) << endl;
            break;
        }
        else if(sum > x) {
            --j;
        }
        else if(sum < x) {
            ++i;
        }
    }
    if(i >= j) {
        cout << "IMPOSSIBLE" << endl;
    }
}
*/

// O(n) time, O(n) space.
int main() {
    int n, x, a;
    map<int, int> mp;
    cin >> n >> x;
    bool found_it = false;
    for(int i = 0; i < n; ++i) {
       cin >> a;
       if(mp.find(x - a) != mp.end()) {
           cout << mp[x-a] + 1 << ' ' << i + 1 << endl;
           found_it = true;
           break;
       } 
       mp[a] = i;
    }
    if(!found_it) cout << "IMPOSSIBLE" << endl;
}