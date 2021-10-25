#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long int ans = 0;
    for(int i = 1; i < n; ++i) {
        while(arr[i-1] > arr[i]) {
            ++arr[i]; ++ans;
        }
    }
    cout << ans << endl;
}