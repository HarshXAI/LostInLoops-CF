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
    ll n,x,y; cin >>n>>x>>y;

    ll common_lcm = (x/__gcd(x,y))*y;
    ll cntx = n/x;
    ll ctny = n/y;

    ll cntcommon = n/common_lcm;

    ll pluscnt = cntx-cntcommon;
    ll minuscnt = ctny-cntcommon;

    ll first_lage = n-pluscnt+1;
    ll lastvaala = n;
    ll sum_pos = (pluscnt*(first_lage+lastvaala))/2;

    ll pehla_nasha =1;
    ll aakhri_nasha = minuscnt;

    ll peechu = (minuscnt*(pehla_nasha+aakhri_nasha))/2;

    cout << sum_pos-peechu<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}