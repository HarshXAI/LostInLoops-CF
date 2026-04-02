#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t int128; // Large calculations ke liye safe type

void solve() {
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    ll low = 1, high = 1e9; // w ki range
    ll ans = 1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        int128 total_area = 0;

        for (int i = 0; i < n; i++) {
            // Har picture ka area: (s[i] + 2*w)^2
            int128 side = s[i] + (int128)2 * mid;
            total_area += side * side;

            // Agar total_area pehle hi c se bada ho gaya, toh loop roko
            if (total_area > c) break;
        }

        if (total_area == (int128)c) {
            ans = mid;
            break;
        } else if (total_area > (int128)c) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}