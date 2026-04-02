#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), a_prime(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> a_prime[i];

    // 1. Mismatch dhoondo
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != a_prime[i]) {
            if (l == -1) l = i;
            r = i;
        }
    }

    // 2. Window ko expand karo a_prime (sorted array) ke upar
    // Left expansion: Jab tak piche wala element chota ya barabar hai
    while (l > 0 && a_prime[l - 1] <= a_prime[l]) {
        l--;
    }

    // Right expansion: Jab tak aage wala element bada ya barabar hai
    while (r < n - 1 && a_prime[r + 1] >= a_prime[r]) {
        r++;
    }

    // 1-based indexing ke liye +1
    cout << l + 1 << " " << r + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}