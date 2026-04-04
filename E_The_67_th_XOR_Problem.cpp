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

struct TrieNode {
    int nxt[2];
    TrieNode() {
        nxt[0] = nxt[1] = -1;
    }
};

struct Trie {
    vector<TrieNode> t;
    Trie() {
        t.pb(TrieNode());
    }

    void daal(int x) {
        int node = 0;
        for (int b = 30; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (t[node].nxt[bit] == -1) {
                t[node].nxt[bit] = (int)t.size();
                t.pb(TrieNode());
            }
            node = t[node].nxt[bit];
        }
    }

    int xordena(int x) {
        int node = 0, ans = 0;
        for (int b = 30; b >= 0; b--) {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if (t[node].nxt[want] != -1) {
                ans |= (1 << b);
                node = t[node].nxt[want];
            } else {
                node = t[node].nxt[bit];
            }
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    cin >> a;

    Trie trie;
    trie.daal(a[0]);

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, trie.xordena(a[i]));
        trie.daal(a[i]);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}