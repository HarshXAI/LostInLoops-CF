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
    int n; cin >>n;
    vi a(n); cin>>a;
    
    a.erase(unique(all(a)),a.end());
    int sz =a.size();
    if(sz ==1){
        cout << 1 << endl;
        return;
    }
    int ans = sz;
    for(int i=1; i< sz-1;i++){
        if((a[i]>a[i-1] && a[i] < a[i+1])|| (a[i]<a[i-1] && a[i] > a[i+1])){
            ans--;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}