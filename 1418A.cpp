#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        // Need total sticks: k for crafting + k*y for buying coal
        // Starting with 1 stick, so need to gain:
        long long need = k * (y + 1) - 1;   // can be up to ~1e18

        // Each trade 1 stick -> x sticks gives net (x-1) sticks
        long long net = x - 1;

        // m = ceil(need / net)
        long long m = (need + net - 1) / net;

        // Total trades = stick-trades + coal-trades (k times)
        cout << (m + k) << "\n";
    }
    return 0;
}
