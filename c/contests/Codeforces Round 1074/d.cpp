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
    int n, m, h;
    cin >> n >> m >> h;
    vll a(n); cin >> a; 
    vector<pair<int, int>> ops(m);
    for (int i = 0; i < m; i++) {
        cin >> ops[i].first >> ops[i].second;
        ops[i].first--; 
    }

    vll current_a = a;
    int aakhri_crash = -1;

    for (int i = 0; i < m; i++) {
        int idx = ops[i].first;
        ll add = ops[i].second;
        if (current_a[idx] + add > h) {
            aakhri_crash = i;
            current_a=a;
        } else {
            current_a[idx] += add;
        }
    }

    vll final_ans = a;
    for (int i = aakhri_crash + 1; i < m; i++) {
        final_ans[ops[i].first] += ops[i].second;
    }

    cout << final_ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}