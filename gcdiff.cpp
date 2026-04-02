#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// GCD nikalne ka function (agar __gcd use nahi karna toh)
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;

    // Sirf aadhe array tak loop chalayenge kyunki pairs check karne hain
    // i aur n-i-1 palindrome pairs hote hain
    for (int i = 0; i < n / 2; i++) {
        ll diff = abs(a[i] - a[n - i - 1]);
        
        // __gcd(0, x) hamesha x hota hai
        ans = __gcd(ans, diff);
    }

    // Agar ans 0 hai, iska matlab array pehle se palindrome hai (x = infinity)
    cout << ans << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}