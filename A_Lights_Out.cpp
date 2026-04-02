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
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];

    // Directions: self + 4 neighbors
    int dx[5] = {0, 1, -1, 0, 0};
    int dy[5] = {0, 0, 0, 1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int toggles = 0;
            for (int k = 0; k < 5; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (0 <= ni && ni < 3 && 0 <= nj && nj < 3) {
                    toggles += a[ni][nj];
                }
            }
            // Initially ON (1). If odd toggles -> becomes OFF (0).
            cout << ((toggles % 2 == 0) ? '1' : '0');
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // This problem has NO T in input.
    solve();
    return 0;
}