#include <iostream>
using namespace std;

bool nums[200005];

int main() {
    int n, x, rounds = 0;
    cin >> n;
    while(n--) {
        cin >> x;
        rounds += !nums[x - 1];
        nums[x] = true;
    }
    cout << rounds << endl;
}

// Note: When x = 1, nums[x - 1] is always false, that accounts for our first round.
