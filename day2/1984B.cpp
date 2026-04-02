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

vector<int> get_digits_reverse(long long n) {
    vector<int> d;
    if(n == 0) {
        d.push_back(0);
        return d;
    }
    while(n > 0){
        d.push_back(n % 10);
        n /= 10;
    }
    return d;   // already reversed
}
void solve() {
    long long n; cin >> n;
    vi rd = get_digits_reverse(n); // [last ... first]
    int m = (int)rd.size();

    // must have at least 2 digits
    if (m < 2) { no; return; }

    // last digit must NOT be 9
    if (rd[0] == 9) { no; return; }

    // first (most significant) digit must be 1
    if (rd.back() != 1) { no; return; }

    // middle digits must not be 0
    for (int i = 1; i <= m-2; i++) {
        if (rd[i] == 0) { no; return; }
    }

    yes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}