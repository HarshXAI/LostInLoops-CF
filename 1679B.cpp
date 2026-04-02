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
    int n , q; cin >>n>>q;
    vll a(n); cin >> a;
    ll current_sum =0;
    for(auto x : a) current_sum += x;
    vll last_updated(n,0);
    ll last_all_val = 0;
    ll last_all_time=0;
    ll timer =1;

    while (q--){
        int t; cin >> t;
        if (t ==1){
            int i,x; cin >> i>> x;
            i--;
            if (last_updated[i] < last_all_time){
                current_sum = current_sum -last_all_val +x;
            }
            else {
                current_sum = current_sum - a[i]+x;

            }
            a[i]=x;
            last_updated[i] = timer;
        }
        else {
            int x ; cin >> x;
            last_all_time = timer;
            last_all_val = x;
            current_sum = (ll)n*x;

        }
        cout << current_sum << "\n";
        timer++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}