#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll max_ans = a[0];
    ll current_sum = a[0];

    for (int i = 1; i < n; i++) {
        // Parity check: (odd-even or even-odd)
        if (abs(a[i] % 2) != abs(a[i-1] % 2)) {
            // Agar pichla sum positive hai toh add karo, warna naye se shuru
            if (current_sum > 0) {
                current_sum += a[i];
            } else {
                current_sum = a[i];
            }
        } else {
            // Parity same hai toh compulsory reset
            current_sum = a[i];
        }
        
        // Har step pe answer update karo
        max_ans = max(max_ans, current_sum);
    }
    cout << max_ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}