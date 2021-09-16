#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_vowel(char c) { 
    return c == 'A' || c == 'E' || c == 'U' || c == 'I' || c == 'O';
}

// compute the cost of changing every character in s to ch.
int compute_cost(string &s, char ch) {
    int cost = 0;
    for(char cs : s) {
        if(cs == ch) continue;
        if(is_vowel(cs) == is_vowel(ch)) cost += 2;
        else cost += 1;
    }
    return cost;
}

int main() {
    int tt;
    cin >> tt;
    for(int tc = 1; tc <= tt; tc++) {
        string s;
        cin >> s;
        vector<int> costs(26, 0);
        for(int i = 0; i < 26; i++) {
            costs[i] = compute_cost(s, i + 'A');
        }
     cout << "Case #" << tc << ": " << *min_element(costs.begin(), costs.end()) << endl;
    }
}