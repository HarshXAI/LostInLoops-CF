#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        if (a == b) {
            cout << 0 << endl;
            continue;
        }

        // Count trailing zeros (powers of 2)
        int x = __builtin_ctzll(a);
        int y = __builtin_ctzll(b);

        // Get the odd part by shifting right
        ll oddA = a >> x;
        ll oddB = b >> y;

        // If the odd parts don't match, we can't transform one to the other
        if (oddA != oddB) {
            cout << -1 << endl;
        } else {
            // Difference in the number of shifts needed
            int diff = abs(x - y);

            // Greedy approach: Shift by 3 (8), then 2 (4), then 1 (2)
            int ans = (diff / 3);  // Count of 8s
            diff %= 3;
            ans += (diff / 2);     // Count of 4s
            diff %= 2;
            ans += diff;           // Count of 2s

            cout << ans << endl;
        }
    }
    return 0;
}