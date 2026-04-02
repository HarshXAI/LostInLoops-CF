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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> queries(T);
    cin >> queries;

    int maxN = 0;
    for (int x : queries) maxN = max(maxN, x);

    // sieve
    vector<bool> pv(maxN + 1, true);
    if (maxN >= 0) pv[0] = false;
    if (maxN >= 1) pv[1] = false;

    for (int i = 2; 1LL * i * i <= maxN; i++) {
        if (pv[i]) {
            for (int j = i * i; j <= maxN; j += i) {
                pv[j] = false;
            }
        }
    }

    // valid primes of form x^2 + y^4
    vector<bool> ans(maxN + 1, false);

    for (int y = 0; ; y++) {
        ll y4 = 1LL * y * y * y * y;
        if (y4 > maxN) break;

        for (int x = 0; ; x++) {
            ll val = 1LL * x * x + y4;
            if (val > maxN) break;

            if (pv[val]) ans[val] = true;
        }
    }

    // prefix count
    vector<int> pref(maxN + 1, 0);
    for (int i = 1; i <= maxN; i++) {
        pref[i] = pref[i - 1] + (ans[i] ? 1 : 0);
    }

    for (int n : queries) {
        cout << pref[n] << "\n";
    }

    return 0;
}