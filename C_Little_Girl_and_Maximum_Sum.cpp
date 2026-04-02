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
    int n,q; cin >>n>>q;
    vll a(n); cin>>a;
    vll freq (n+2,0);
    for(int i=0;i<q;i++){
        int l,r;
        cin >>l>>r;
        freq[l]++;
        freq[r+1]--;
    }
    vll actul_freq;
    ll cursum=0;
    for(int i=1;i<=n;i++){
        cursum+=freq[i];
        actul_freq.pb(cursum);
    }
    sort(all(a));
    sort(all(actul_freq));
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(ll)(actul_freq[i]*a[i]);
    }
    cout <<ans<<"\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    
    while (T--) solve();
    return 0;
}