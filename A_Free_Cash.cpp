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

void solve() {
    int n; 
    cin >> n;

    int h, m;
    cin >> h >> m;

    int cnt = 1, ans = 1;

    for (int i = 1; i < n; i++) {
        int nh, nm;
        cin >> nh >> nm;

        if (nh == h && nm == m) {
            cnt++;
        } else {
            cnt = 1;
            h = nh;
            m = nm;
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}