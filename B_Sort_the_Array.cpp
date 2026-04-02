#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define yes cout << "yes\n"
#define no cout << "no\n"

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) os << (i ? " " : "") << v[i];
    return os;
}

void solve() {
    int n; 
    cin >> n;
    
    vi a(n);
    cin >> a;

    vi b = a;
    sort(all(b));

    int l = 0;
    while (l < n && a[l] == b[l]) l++;

    if (l == n) {
        yes;
        cout << 1 << " " << 1 << '\n';
        return;
    }

    int r = n - 1;
    while (r >= 0 && a[r] == b[r]) r--;

    reverse(a.begin() + l, a.begin() + r + 1);

    if (a == b) {
        yes;
        cout << l + 1 << " " << r + 1 << '\n';
    } else {
        no;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--) solve();
    return 0;
}