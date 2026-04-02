#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> ans(n);
    for (int i = 0; i < n; ) {
        int j = i;
        // 1. Group dhoondo (v[i] se v[j-1] tak same size hai)
        while (j < n && v[j] == v[i]) {
            j++;
        }

        int group_size = j - i;
        
        // 2. Agar group size 1 hai, toh impossible hai
        if (group_size == 1) {
            cout << -1 << endl;
            return; // Agle test case par jao
        }

        // 3. Cyclic Shift: Last index ko pehle laao, baaki ko aage dhakelo
        // Example: 1 2 3 -> 3 1 2 (Indices)
        ans[i] = j; // i-th student gets shoe of j-th student
        for (int k = i + 1; k < j; k++) {
            ans[k] = k; // k-th student gets shoe of (k)-th student (index wise k-1)
        }
        
        i = j; // Agle group par jump karo
    }

    // Output the result
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}