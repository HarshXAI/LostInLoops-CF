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
    int n; cin >> n;
    vector<string> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int total_ops = 0;

    // Sirf quarter grid pe loop chalao
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < (n + 1) / 2; j++) {
            // Group ke 4 members ki values uthao
            int val1 = a[i][j] - '0';
            int val2 = a[j][n - 1 - i] - '0';
            int val3 = a[n - 1 - i][n - 1 - j] - '0';
            int val4 = a[n - 1 - j][i] - '0';

            int ones = val1 + val2 + val3 + val4;
            
            // In charo ko same karne ka min cost
            total_ops += min(ones, 4 - ones);
        }
    }
    cout << total_ops << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}