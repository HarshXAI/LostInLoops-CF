#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    
    ll term1 = n % MOD;
    ll term2 = (n + 1) % MOD;
    ll term3 = (4 * n - 1) % MOD;
    
    ll ans = (((term1 * term2) % MOD) * term3) % MOD;
    ans = (ans * 337) % MOD;
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}