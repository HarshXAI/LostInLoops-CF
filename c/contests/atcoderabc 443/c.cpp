#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i; return is;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < v.size(); i++) os << (i > 0 ? " " : "") << v[i];
    return os;
}

void solve() {
    ll n, t;
    cin >> n >> t;
    vll a(n);
    cin >> a;

    ll ans = 0;
    ll opens_at = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > opens_at) {
            ans += (a[i] - opens_at);
            opens_at = min(t, a[i] + 100);
        }
        if (opens_at >= t) break;
    }

    if (opens_at < t) {
        ans += (t - opens_at);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}