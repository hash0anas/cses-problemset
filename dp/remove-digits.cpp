#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 5, mod = 1e9 + 7;

int memo[mxN], n; 

int top_down(int x) {
    if(x == 0) return 0;
    if(memo[x] > 0) return memo[x];

    memo[x] = INT_MAX;
    for(char digit : to_string(x)) {
        memo[x] = min(memo[x], top_down(x - (digit - '0')) + 1);
    }
    return memo[x];
}

int main() {
    cin >> n;
    cout << top_down(n) << endl;
}