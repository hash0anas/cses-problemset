#include <iostream>
#include <vector>

using namespace std;

vector<int> build_lps_table(const string p) {
    int n = p.size();
    vector<int> lps(n);
    int j = 0;
    for(int i = 1; i < n; ++i) {
        while(j > 0 && p[i] != p[j]) {
            j = lps[j - 1];
        }
        if(p[i] == p[j])
            ++j;
        lps[i] = j;
    }
    return lps;
}

int main() {
    string s, p;
    cin >> s >> p;
    int ns = s.size(), np = p.size();
    vector<int> lps = build_lps_table(p);
    int i = 0, j = 0, ans = 0;
    while(i < ns) {
        if(s[i] == p[j]) {
            ++i, ++j;
        }
        else {
            if(j > 0)
                j = lps[j-1];
            else {
                ++i; // move i only when at the start of pattern, i.e j = 0
            } 
        }
        if(j == np) {
            ++ans; 
            j = lps[j-1];
        }
    }
    cout << ans << endl;
}

// Note: KMP algorithm, takes 0(m) space, and 0(n + m) time.
// Will run for at most 2(n+m) times.
// In lps, patterns could overlap ... e.g. ababa >> 3. (aba) is both the prefix and the suffix.
