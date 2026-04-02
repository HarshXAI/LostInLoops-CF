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
    cin >>a;
    int l=0,r=n-1;
    int kaam =1;
    int jyaada =n;
    while (l<r)
    {
        if(a[l] == kaam){
            l++;
            kaam++;
        }
        else if (a[r] == jyaada){
            r--;
            jyaada--;
        }
        else if(a[l] == jyaada){
            l++;
            jyaada--;
        }
        else if(a[r]==kaam){
            r--;
            kaam++;
        }
        else{
            break;
        }


    }
    if (l < r) {
        cout << l + 1 << " " << r + 1 << endl;
    } else {
        cout << -1 << endl;
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