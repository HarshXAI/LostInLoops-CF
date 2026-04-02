#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i; return is;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < v.size(); i++) os << (i > 0 ? " " : "") << v[i];
    return os;
}

void solve() {
    int n;cin>>n;
    vi a(n);
    vi b(n);
    vi c(n);

    cin >>a >>b >> c;

    auto get_best = [&] (vi &v){
        vector<pair<int,int>> pairs;
        for(int i=0;i<n;i++){
            pairs.pb({v[i],i});
        }

        sort(rall(pairs));
        if(pairs.size()>3) pairs.resize(3);
        return pairs;
        
    };
    auto bestA = get_best(a);
    auto bestB = get_best(b);
    auto bestC = get_best(c);

    ll ans = 0;
    for(auto p1:bestA){
        for(auto p2:bestB){
            for(auto p3:bestC){
                if(p1.second!=p2.second && p1.second!= p3.second && p2.second!= p3.second){
                    ans = max(ans,(ll)p1.first + p2.first + p3.first) ;
                }
            }
        }
    }
    cout <<ans<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}