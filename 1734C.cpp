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
    int n; cin >>n;
    string t; cin >>t;
    ll total_cost =0;
    vector<bool> removed(n+1,false);
    for(int k=1;k<=n;k++){
        for(int m=k;m <= n;m+=k)
        {
            if(t[m-1]=='1') break;
            if(!removed[m]){
                total_cost+=(ll)k;
                removed[m] = true;
            }
        }
    }
    cout<< total_cost<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}