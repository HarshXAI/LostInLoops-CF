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
    ll n, k;
    cin >> n >> k;

    ll low = 0, high = 2e9; 
    ll ans = high;

    while (low <= high) {
        ll x = low + (high - low) / 2;
        
        __int128 total = (__int128)(x + 1) * (2 * n + x) / 2;

        if (total >= k) {
            ans = x;
            high = x - 1;
        } else {
            low = x + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T = 1;
    // cin >> T;
    // while (T--) 
    solve();
    return 0;
}