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
    int n, q; // yahan q hai, k nahi
    cin >> n >> q;
    vi a(n); cin >> a;
    vi queries(q); cin >> queries;

    vll ps(n, 0); 
    ps[0] = a[0];
    for (int i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + (ll)a[i];
    }

    vi maxx(n);
    int curr_max = 0;
    for (int i = 0; i < n; i++) {
        curr_max = max(curr_max, a[i]);
        maxx[i] = curr_max;
    }
    
    for(int i = 0; i < q; i++) {
        int leg_len = queries[i];
        // upper_bound pehla element deta hai jo leg_len se BADA ho
        auto it = upper_bound(all(maxx), leg_len);
        
        // Agar it, maxx.begin() pe hai, matlab pehla hi step leg_len se bada hai
        if (it == maxx.begin()) {
            cout << 0 << " ";
        } else {
            // it se ek pehle wala index tak Timur ja sakta hai
            int idx = distance(maxx.begin(), it) - 1;
            cout << ps[idx] << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}