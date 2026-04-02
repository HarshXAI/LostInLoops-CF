#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

void solve() {
    int n, c_start;
    if (!(cin >> n >> c_start)) return;
    c_start--;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<vector<bool>> can_pass(n, vector<bool>(n, false));
    for (int j = 0; j < n; j++) {
        bool blocked = false;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i][j] == '.') {
                can_pass[i][j] = true;
            } else {
                if (!blocked) {
                    can_pass[i][j] = true;
                } else {
                    can_pass[i][j] = false;
                }
                blocked = true;
            }
        }
    }

    vector<vector<bool>> can_reach(n, vector<bool>(n, false));
    can_reach[n - 1][c_start] = true;

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (!can_reach[i][j]) continue;
            for (int next_j = j - 1; next_j <= j + 1; next_j++) {
                if (next_j >= 0 && next_j < n) {
                    if (can_pass[i - 1][next_j]) {
                        can_reach[i - 1][next_j] = true;
                    }
                }
            }
        }
    }

    string res = "";
    for (int j = 0; j < n; j++) {
        res += (can_reach[0][j] ? '1' : '0');
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) solve();
    return 0;
}