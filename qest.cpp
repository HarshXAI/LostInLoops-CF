#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        ll max_ans = 0;
        ll prefix_sum = 0;
        int max_b = 0;

        // Loop runs only up to the quests we can actually reach
        for (int i = 0; i < min(n, k); i++) {
            prefix_sum += a[i];
            max_b = max(max_b, b[i]);

            // i is 0-indexed, so we have used (i + 1) moves
            int remaining_moves = k - (i + 1);
            
            ll current_total = prefix_sum + (1LL * max_b * remaining_moves);
            max_ans = max(max_ans, current_total);
        }
        cout << max_ans << endl;
    }
    return 0;
}