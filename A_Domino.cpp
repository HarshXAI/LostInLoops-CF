#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int su = 0, sl = 0;
    bool hasMixed = false;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        su += x;
        sl += y;
        if ((x % 2) != (y % 2)) hasMixed = true;
    }

    if (su % 2 == 0 && sl % 2 == 0) {
        cout << 0;
    } else if (su % 2 == 1 && sl % 2 == 1 && hasMixed) {
        cout << 1;
    } else {
        cout << -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}