#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cur = 1, ans = 1;
    for(int i = 1; i < s.length(); i++) {
        if(s[i] == s[i-1]) ++cur;
        else cur = 1;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}