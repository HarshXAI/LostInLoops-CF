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
    // THINK FIRST, CODE LATER
    // 1) constraints?
    // 2) edge cases?
    // 3) approach in 2 lines
    int n; cin >> n;
    vi a(n); cin>>a;

    vi p_max(n);
    int mx=0;
    ll total_sum=0;
    for (int i=0;i<n;i++){
        mx = max(a[i],mx);
        p_max[i] =mx;
        total_sum+=a[i];
    }
    vll p_sum(n,0);
    p_sum[0]=a[0];
    for(int i=1; i<n;i++){
        p_sum[i]=(ll)p_sum[i-1]+a[i];
    }
    vll ans(n);

    for( int k=0;k<n;k++){
        ans[k]= (ll)(total_sum- p_sum[n-k-1])+p_max[n-k-1];
    }
    cout<< ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}