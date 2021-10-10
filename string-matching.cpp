#include <iostream>
#include <vector>

using namespace std;
void naive_string_matching(string, string);
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
                ++i;// move i only when at the start of pattern, i.e j = 0
            } 
        }
        if(j == np) {
            ++ans; 
            j = lps[j-1];
        }
    }
    // cout << ans << endl;
    naive_string_matching(s, p);
}

void naive_string_matching(string text, string pattern) {
    int occs = 0;
    for(int i = 0; i < text.size(); ++i) {
        bool flag = true;
        for(int j = 0; j < pattern.size(); ++j) {
            if(text[i+j] != pattern[j]) {
                flag = false;
                break;
            }
        }
        if(flag) occs++;
    }
    cout << "we have " << occs << " occurences\n";
}