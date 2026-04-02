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
    int n,k;
    cin >>n>>k;
    vi c(n);
    cin >> c;
    vi max1(k+1,-1), max2(k+1,-1), last_pos(k+1,0);
    for(int i=1;i<=n;i++){
        int color = c[i-1];
        int gap = i-last_pos[color]-1;
        if(gap > max1[color]){
            max2[color]=max1[color];
            max1[color] = gap;
        }
        else if(gap>max2[color]){
            max2[color] = gap;
        }
        last_pos[color]=i;
    }

    for (int color = 1; color <= k; color++) {
        int gap = n - last_pos[color];
        if (gap > max1[color]) {
            max2[color] = max1[color];
            max1[color] = gap;
        } else if (gap > max2[color]) {
            max2[color] = gap;
        }
    }
    int final_ans = 1e9;

    for (int color = 1; color <= k; color++) {
        int current_color_max_step = max(max1[color] / 2, max2[color]);
        
        final_ans = min(final_ans, current_color_max_step);
    }

    cout << final_ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}