#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define yes cout << "YES\n"
#define no cout << "NO\n"



void solve() {
    ll x;
    cin >> x;

    ll a1 = 1, a2 = x;

    for (ll d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            ll b = x / d;
            if (lcm(d, b) == x) {
                if (max(d, b) < max(a1, a2)) {
                    a1 = d;
                    a2 = b;
                }
            }
        }
    }

    cout << a1 << " " << a2 << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}