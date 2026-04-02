
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
    int n;cin >>n;
    ll lb= (ll)(n*(n-1))/2;
    vll b(lb); cin >>b;
    sort(all(b));
    int curr_indx = 0;
    vll ans;
    for (int i = 1; i < n; i++)
    {
        ans.pb(b[curr_indx]);
        curr_indx+=n-i;
    }
    ans.pb(1e9);
    cout << ans<< endl;    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}