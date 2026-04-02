#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Use long long because costs can sum up to > 10^9
typedef long long ll;

void solve() {
    int N;
    ll W;
    cin >> N >> W;

    // Cycle size 2W hai
    int mod_size = 2 * W;
    vector<ll> buckets(mod_size, 0);

    for (int i = 1; i <= N; ++i) {
        ll c;
        cin >> c;
        // Index i ko 2W ke cycle mein map kar rahe hain
        buckets[i % mod_size] += c;
    }

    // Ab humein 'buckets' array (circular) mein size W ka minimum sum subarray dhoondna hai
    ll current_sum = 0;

    // Pehla window calculate karo (indices 0 to W-1)
    for (int i = 0; i < W; ++i) {
        current_sum += buckets[i];
    }

    ll min_cost = current_sum;

    // Sliding Window Logic:
    // Window ko ek step aage badhate jao
    for (int i = 1; i < mod_size; ++i) {
        // Piche wala element hatao
        current_sum -= buckets[i - 1];
        
        // Aage wala element jodo (Circular logic ke liye modulo use kiya)
        // Window ka naya end element: (i + W - 1)
        int next_idx = (i + W - 1) % mod_size;
        current_sum += buckets[next_idx];

        // Minimum update karo
        if (current_sum < min_cost) {
            min_cost = current_sum;
        }
    }

    cout << min_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}