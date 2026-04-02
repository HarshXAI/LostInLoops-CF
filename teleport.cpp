#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> costs(n);
    for (int i = 0; i < n; i++) {
        ll a_i;
        cin >> a_i;
        costs[i] = a_i + (i + 1);
    }
    sort(costs.begin(), costs.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (c >= costs[i]) {
            c -= costs[i];
            count++;
        } else {
            break;
        }
    }

    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;

}