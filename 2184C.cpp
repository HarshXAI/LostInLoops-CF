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
    int n, k ; cin >>n>>k;
    bool got_odd = false;
    bool found = false;
    int ans = 0;
    if(n == k){
        cout <<0<<"\n";
        return;
    }

    while (n >0 && n >k){
        
            if (n&1) got_odd = true;
            int curr = n/2;
            ans++;
            if (curr == k) {
                found = true;
                break;}
            if(got_odd){
                if(curr+1 == k){
                    found = true;
                    break;
                }
            }
            n=curr;
    }
    if(found){
        cout << ans<<endl;
        return;
    }
    else {
        cout <<-1<<"\n";
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}