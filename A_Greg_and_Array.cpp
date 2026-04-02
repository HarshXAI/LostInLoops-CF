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
    int n,m,k; cin >>n>>m>>k;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    struct Op{
        int l,r;
        ll d;
    };
    vector<Op> qs(m+1);
    for(int i=1;i<=m;i++){
        cin >> qs[i].l >>qs[i].r >>qs[i].d;
    }
    vll Ops_freq(m+2,0);
    for(int i=1;i<=k;i++){
        int x, y; cin >> x >> y;
        Ops_freq[x]++;
        Ops_freq[y+1]--;

    }
    vll Asli_ops(m+2,0);
    for(int i=1;i<=m;i++){
        Asli_ops[i]=Asli_ops[i-1]+Ops_freq[i];
    }
    vll diff(n+2,0);
    for(int i=1;i<=m;i++){
        ll total_val = Asli_ops[i] * qs[i].d;
        diff[qs[i].l]+=total_val;
        diff[qs[i].r+1]-=total_val;
    }
    ll current_s=0;
    for(int i=1;i<=n;i++){
        cout << a[i]+current_s+diff[i]<<" ";
        current_s+=diff[i];
    }
    cout <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    
    while (T--) solve();
    return 0;
}