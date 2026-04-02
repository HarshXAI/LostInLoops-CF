#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define yes cout << "YES\n"
#define no cout << "NO\n"

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) os << (i ? " " : "") << v[i];
    return os;
}

#ifdef LOCAL
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A,B>& p){
    return os << '(' << p.first << ", " << p.second << ')';
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    os << '[';
    for (int i = 0; i < (int)v.size(); i++){
        if (i) os << ", ";
        os << v[i];
    }
    return os << ']';
}
inline void dbg_out(){ cerr << '\n'; }
template<typename Head, typename... Tail>
inline void dbg_out(Head H, Tail... T){
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define dbg(...) ((void)0)
#endif

void solve() {
    int n; cin >>n;
    vll a(n); cin >>a;
    vll ans(n);
    for (int i=1; i<n-1;i++){
        ans[i] = (a[i-1] + a[i+1] - 2 * a[i]) / 2;
    }
    ll d1 = a[1]-a[0];
    ll akhri = a[n-1]-a[n-2];

    ll sum1=0;
    for(int i=1; i<n-1;i++)sum1+=ans[i]*i;
    ans[n-1]=(a[0]-sum1)/(n-1);
    ll sum2=0;
    for(int i=1; i<n-1;i++)sum2 += ans[i] * (n-1-i);
    ans[0]= (a[n-1]-sum2)/(n-1);
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