#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the array in descending order
    sort(a.begin(), a.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
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