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
vector<string> ans;
void solve(vector<int> freq, string curr,int n) {
    // THINK FIRST, CODE LATER
    // 1) constraints?
    // 2) edge cases?
    // 3) approach in 2 lines
    if(curr.size()==n){
        ans.pb(curr);
    }
    for(int i=0; i<26;i++){
        if(freq[i]==0)continue;
        vector<int> newfreak = freq;

        newfreak[i]--;
        string newcurr = curr;
        newcurr  +=char('a'+i);
        solve(newfreak,newcurr,n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >>s;
    vector<int> freq(26,0);
    for(auto i:s){
        freq[i-'a']++;
    }
    string curr="";
    solve(freq,curr,s.size());
    cout <<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i<<"\n";
    }
    return 0;
}