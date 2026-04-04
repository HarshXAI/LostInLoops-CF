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

vector<int> amazonprime;

void sieve(int bas = 200000) {
    vector<bool> is_prime(bas + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= bas; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= bas; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= bas; i++) {
        if (is_prime[i]) amazonprime.pb(i);
    }
}

void solve() {
    int n;
    cin >> n;

    vll a(n);

    if (n == 2) {
        cout << 1 << " " << 2 << '\n';
        return;
    }

    a[0] = amazonprime[0];
    for (int i = 1; i < n - 1; i++) {
        a[i] = 1LL * amazonprime[i - 1] * amazonprime[i];
    }
    a[n - 1] = amazonprime[n - 2];

    cout << a << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}