#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// C++17 mein std::gcd available hai, par manual likhna safe hai
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    
    // last_idx array ko 0 se initialize karo
    // Isme hum store karenge ki konsi value (1-1000) kis max index pe aayi hai
    vector<int> last_idx(1001, 0);
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        last_idx[x] = i; // Max index update hoti rahegi
    }

    int max_sum = -1;

    // Ab hum 1000x1000 ka loop chalayenge
    // Kyunki n bhale hi 2e5 ho, unique values sirf 1000 hi hain
    for (int i = 1; i <= 1000; i++) {
        if (last_idx[i] == 0) continue; // Agar ye number array mein hai hi nahi
        
        for (int j = 1; j <= 1000; j++) {
            if (last_idx[j] == 0) continue;
            
            // Check if coprime
            if (gcd(i, j) == 1) {
                max_sum = max(max_sum, last_idx[i] + last_idx[j]);
            }
        }
    }

    cout << max_sum << "\n";
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