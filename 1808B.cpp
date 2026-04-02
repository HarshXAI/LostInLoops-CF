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
    int n, m;
    cin >> n >> m;

    // Humein input ko columns ke hisaab se store karna hai
    // columns[0] mein saare players ka pehla number, columns[1] mein dusra, etc.
    vector<vll> columns(m, vll(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> columns[j][i];
        }
    }

    ll total_winnings = 0;

    // Har column ko independently solve karenge
    for (int j = 0; j < m; j++) {
        sort(all(columns[j])); // Sorting makes absolute difference easy

        ll current_column_sum = 0;
        for (int i = 0; i < n; i++) {
            // Formula: x_i * (pichle elements ka count - aage wale elements ka count)
            // i elements chote hain, (n - 1 - i) elements bade hain
            ll contribution = (ll)columns[j][i] * (2LL * i - n + 1);
            current_column_sum += contribution;
        }
        total_winnings += current_column_sum;
    }

    cout << total_winnings << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}