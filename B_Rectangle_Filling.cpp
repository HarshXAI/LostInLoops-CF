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
    int n,m; cin >> n >> m;
    vector<vector<char>> v(n,vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = s[j];
        }
    }

    if(v[0][0] == v[n-1][m-1] || v[0][m-1] == v[n-1][0]){
        yes;
    }
    else{
        string ans = "YES";
        bool asambhav = true;

        for(int j = 0; j < m - 1; j++){
            if (v[0][j] != v[0][j+1] || v[n-1][j] != v[n-1][j+1]){
                asambhav = false;
            }
        }
        if (v[0][0] == v[n-1][0]) asambhav = false;
        if (asambhav) ans = "NO";

        asambhav = true;
        for(int j = 0; j < n - 1; j++){
            if (v[j][0] != v[j+1][0] || v[j][m-1] != v[j+1][m-1]){
                asambhav = false;
            }
        }
        if (v[0][0] == v[0][m-1]) asambhav = false;
        if (asambhav) ans = "NO";

        if(ans == "NO") no;
        else yes;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}