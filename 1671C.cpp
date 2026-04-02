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
    ll x; cin >>x;
    vll a(n); cin >> a;
    sort(all(a));
    vll psa(n+1,0);
    for(int i=0;i<n;i++){
        psa[i+1]= (ll)psa[i]+a[i];
    }
    ll total_ans=0;
    for(int k=1;k<=n;k++){
        if(psa[k]<=x)

        {
            ll d = (x-psa[k])/k;
            total_ans += (d + 1);
    }
    }
    cout << total_ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}