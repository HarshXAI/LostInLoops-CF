#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    sort(a.begin(), a.end());
    if (a[0] != 1) {
        cout << "NO\n";
        return;
    }
    ll s = 1; 
    for (int i = 1; i < n; ++i) {
        if (a[i] > s) {
            cout << "NO\n";
            return;
        }
        s += a[i];
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}