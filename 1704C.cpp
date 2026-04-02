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
    int n, m; cin >>n>>m;
    vi a(m); cin >> a;
    vi d(m);
    sort(all(a));
    vi gaps;
    for(int i=0;i<m-1;i++){
        gaps.pb(a[i+1] - a[i] - 1);
    }
    gaps.pb(n - a[m-1] + a[0] - 1);
    sort(rall(gaps));

    ll saved = 0;
    ll time_passed = 0;
    for(int g:gaps){
        int current_gap_size = g - 2 * time_passed;

        if (current_gap_size <= 0) break;
        if (current_gap_size == 1 || current_gap_size == 2) {
            
            saved += 1;
            time_passed += 1;
        } else {
            saved += (current_gap_size - 1);
            time_passed += 2;
        }
    }
    cout << n - saved << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}