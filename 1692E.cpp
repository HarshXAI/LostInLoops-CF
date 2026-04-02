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
    int n, s; cin >> n >> s;
    vi a(n); cin >> a;

    ll total_sum = 0;
    for(int x : a) total_sum += x;

    if (total_sum < s) {
        cout << -1 << "\n";
        return;
    }

    int l = 0, max_len = 0, curr_sum = 0;
    for (int r = 0; r < n; r++) {
        curr_sum += a[r];
        
        while (curr_sum > s) {
            curr_sum -= a[l];
            l++;
        }
        
        if (curr_sum == s) {
            max_len = max(max_len, r - l + 1);
        }
    }

    cout << n - max_len << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}