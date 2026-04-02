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
    int n; cin >> n;
    string s; cin >> s;
    int ans = 1e9;
    for(int i=97; i <=122; i++){
        char target = (char)i;
        int l =0, r=n-1;
        int current_removal=0;
        bool possible = true;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
            if (s[l]==target){
                current_removal++;
                l++;
            }
            else if(s[r]== target){
                current_removal++;
                r--;
            }
            else {
                 possible= false;
                 break;
            }

        }
    }
    if(possible) ans = min (ans, current_removal);
    }
    if (ans==1e9) { cout << -1 <<"\n";
    return;}
    else{
        cout << ans << endl;
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