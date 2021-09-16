#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<bool> there(n+1, false);
    for (int _ = 0; _ < n - 1; _++){
        cin >> x;
        there[x] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(there[i] == false) {
            cout << i << endl;
            break;
        }
    }
}