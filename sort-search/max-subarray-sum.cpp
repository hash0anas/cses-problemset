#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    ll n, ans = -1e18, msf = -1e18, a; 
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        msf = max(0ll + a, msf + a);
        ans = max(ans, msf);
    }
    cout << ans << endl;
}