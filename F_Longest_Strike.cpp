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

void solve(){
    int n, k; 
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;

    map<int,int> freq;
    for(int x : a) freq[x]++;

    int bestL = -1, bestR = -1;
    int curL = -1, curR = -1;

    for(auto &it : freq){
        int x = it.first;
        int c = it.second;

        if(c >= k){
            if(curL == -1){              // start new segment
                curL = curR = x;
            } else if(x == curR + 1){    // extend
                curR = x;
            } else {                     // break, evaluate
                if(bestL == -1 || (curR - curL) > (bestR - bestL)){
                    bestL = curL; bestR = curR;
                }
                curL = curR = x;
            }
        } else {
            // freq < k breaks the segment
            if(curL != -1){
                if(bestL == -1 || (curR - curL) > (bestR - bestL)){
                    bestL = curL; bestR = curR;
                }
                curL = curR = -1;
            }
        }
    }

    // last segment
    if(curL != -1){
        if(bestL == -1 || (curR - curL) > (bestR - bestL)){
            bestL = curL; bestR = curR;
        }
    }

    if(bestL == -1) cout << -1 << "\n";
    else cout << bestL << " " << bestR << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}