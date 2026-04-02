#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Function to calculate sum of digits
int sum_of_digits(ll n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve() {
    ll x; 
    cin >> x;
    if (x % 9 != 0) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (ll y = x; y <= x + 100; y++) {
        if (y - sum_of_digits(y) == x) {
            ans++;
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}