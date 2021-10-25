#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    vector<bool> paired(n);
    for(int &x : v) cin >> x;
    sort(begin(v), end(v));
    int i = 0, j = n - 1;
    int ans = 0;
    while(i < j) {
        if(v[i] + v[j] <= x) { // two kids fit in a gondola
            ++ans;
            paired[i] = paired[j] = true;
            ++i; --j;
        }
        else {
            --j;
        }
    }
    for(bool have_gondola : paired) {
        ans += have_gondola == false;
    }
    cout << ans << endl;
}