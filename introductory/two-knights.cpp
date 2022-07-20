#include <iostream>
using namespace std;

// In a nutshell, # total to put on grid - # 
int main() {
    int n; cin >> n;
    for(int k = 1; k <= n; ++k) {
        long long x = k * k;
        cout << (x * (x - 1)) / 2 - 4 * (k - 1) * (k - 2) << endl;
    }
}