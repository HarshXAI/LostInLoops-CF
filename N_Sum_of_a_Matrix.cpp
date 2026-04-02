#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) os << " ";
        os << v[i];
    }
    return os;
}

void rec(int i, int j, int r, int c,
         vector<vector<int>>& a,
         vector<vector<int>>& b,
         vector<vector<ll>>& ans) {
    
    // saari rows khatam
    if (i == r) return;

    // current row khatam, next row pe jao
    if (j == c) {
        rec(i + 1, 0, r, c, a, b, ans);
        return;
    }

    // current cell ka sum
    ans[i][j] = a[i][j] + b[i][j];

    // next column
    rec(i, j + 1, r, c, a, b, ans);
}

void solve(vector<vector<int>>& a, vector<vector<int>>& b, int r, int c, vector<vector<ll>>& ans) {
    rec(0, 0, r, c, a, b, ans);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j) cout << " ";
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<vector<int>> a(r, vector<int>(c));
    vector<vector<int>> b(r, vector<int>(c));
    vector<vector<ll>> ans(r, vector<ll>(c));

    cin >> a;
    cin >> b;

    solve(a, b, r, c, ans);

    return 0;
}