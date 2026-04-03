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
    vi a;
    int n,k;cin >>n>>k;
    int cp=n;
    for(int i=2;i*i<=n;i++){
        if(cp%i==0){
            // cout<<"yaha"<<endl;
            while(cp%i==0){
                a.pb(i);
                cp/=i;
            }
        }
        // cout <<i<<" "<<endl;

    }
    if (cp > 1) a.pb(cp);
    // cout <<"break\n";
    // cout <<"a "<<a<<endl;
    if(a.size()<k)cout <<-1;
    else if(a.size()==k){
        cout <<a;
        return;
    }
    else{
        
        for(int i=0;i<k-1;i++){
            cout << a[i]<<" ";
        }
        int last=1;
        for(int i=k-1;i<a.size();i++){
            last*=a[i];
        }
        cout <<last<<endl;
       
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
