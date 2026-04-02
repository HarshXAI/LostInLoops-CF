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
    int n; cin >>n;
    vll a(n);
    cin >>a;
    vll b = a;
    sort(all(b));
    ll mex = 0;
    for (ll x:b){
        if(x==mex)mex++;
        else if(x> mex)break;
    }
    ll need = mex+1;
    int first =-1,last=-1;
    for (int i = 0; i < n; i++) {
        if (a[i] == need) {
            if (first == -1) first = i;
            last = i;
        }
    }

    if (first != -1) {
        vector<int> outside(mex, 0);

        for (int i = 0; i < first; i++) {
            if (a[i] < mex) outside[a[i]] = 1;
        }
        for (int i = last + 1; i < n; i++) {
            if (a[i] < mex) outside[a[i]] = 1;
        }

        for (int x = 0; x < mex; x++) {
            if (!outside[x]) {
                no;
                return;
            }
        }
        yes;
        return;
    }
    int freq_mex = 0;
    bool greater_than_mex = false;

    for (ll x : a) {
        if (x == mex) freq_mex++;
        if (x > mex) greater_than_mex = true;
    }

    if (greater_than_mex || freq_mex >= 2) yes;
    else no;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}