#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Sirf unhi x[i] ko rakho jo pichle wale se chhote hon
        vector<int> queries;
        int min_x = 31; // x[i] max 30 hota hai
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (x < min_x) {
                queries.push_back(x);
                min_x = x;
            }
        }

        // Ab queries vector ka size max 30 hi hoga!
        // Isliye complexity O(n * 30) ho jayegi jo ki O(n) hai.
        for (int x : queries) {
            int val = (1 << (x - 1));
            int divisor = (1 << x);
            for (int j = 0; j < n; j++) {
                if (a[j] % divisor == 0) {
                    a[j] += val;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}