#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        // Find smallest multiple of i that is >= l
        // Logic: (l + i - 1) / i gives ceiling
        int multiple = ((l + i - 1) / i) * i;

        if (multiple > r) {
            cout << "NO\n";
            return;
        }
        ans.push_back(multiple);
    }

    cout << "YES\n";
    for (int x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}