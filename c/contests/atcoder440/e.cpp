#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

// State structure store karne ke liye
struct State {
    ll sum;             // Current Sum
    int last_idx;       // Last modified index (Duplicate prevention ke liye)
    vector<int> c;      // Flow vector: c[i] = cookies moved from i to i+1

    // Priority Queue ke liye comparator (Max Heap)
    bool operator<(const State& other) const {
        return sum < other.sum;
    }
};

void solve() {
    int n;
    ll k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 1. Descending Sort
    sort(a.rbegin(), a.rend());

    // 2. Differences calculate karo
    vector<ll> d;
    for (int i = 0; i < n - 1; i++) {
        d.push_back(a[i] - a[i + 1]);
    }

    // 3. Priority Queue Setup
    priority_queue<State> pq;
    
    // Initial State: All cookies at index 0 (c vector is all 0s)
    ll initial_sum = a[0] * k;
    vector<int> initial_c(n - 1, 0); 
    
    pq.push({initial_sum, 0, initial_c});

    // 4. Extract Top X
    while (x--) {
        if (pq.empty()) break;

        State top = pq.top();
        pq.pop();

        cout << top.sum << "\n";

        // Branching: Try incrementing c[i] for i >= last_idx
        // Ye loop ensure karta hai ki hum piche mud ke changes na karein (Unique States)
        for (int i = top.last_idx; i < n - 1; i++) {
            
            // Validity Check: Kya hum index i par flow badha sakte hain?
            bool can_increment = false;
            if (i == 0) {
                if (top.c[0] < k) can_increment = true;
            } else {
                if (top.c[i] < top.c[i - 1]) can_increment = true;
            }

            if (can_increment) {
                // Nayi state banao
                State next_state = top;
                next_state.sum -= d[i];
                next_state.c[i]++;
                next_state.last_idx = i; // Update last_idx to enforce order
                
                pq.push(next_state);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}