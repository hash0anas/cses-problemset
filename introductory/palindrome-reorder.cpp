#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> count(26);
    for(char ch : s) {
        count[ch - 'A']++;
    }
    // Now, if s is of even length, we can't have any char of odd frequency.
    // if s is of odd lenght, we can have only a single char of odd frequency.
    int odd_count = 0;
    for(int i = 0; i < 26; ++i) {
        odd_count += (count[i] & 1);
    }
    if(!(n & 1) && odd_count > 0 || (n & 1) && odd_count != 1) {
        cout << "NO SOLUTION\n";
    }
    else {
        string pal_s (n, '0');
        int pal_index = 0;
        for(int i = 0; i < 26; ++i) {
            if(count[i] & 1) {
                pal_s[n / 2] = 'A' + i;
                --count[i];
            }
            while(count[i]) { // if there's count 
                pal_s[pal_index] = 'A' + i;
                pal_s[n - 1 - pal_index++] = 'A' + i;            
                count[i] -= 2;
            }
        }
        cout << pal_s << endl;
    }
}