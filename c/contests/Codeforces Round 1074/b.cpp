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

ll calculate_value (const vector <int> &b){
    if (b.empty()) return 0;
    ll sum = 0;
    int cur_max = -1;
    for(int x : b) {
        cur_max = max(cur_max, x);
        sum += cur_max;
    }
    return sum;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    ll best_ans = calculate_value(a); 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i], a[j]); 
            best_ans = max(best_ans, calculate_value(a));
            swap(a[i], a[j]); 
        }
    }
    cout << best_ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}