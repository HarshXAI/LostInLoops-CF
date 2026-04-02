#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    vector<long long> a(m);
    for (auto &x : a) cin >> x;

    long long time = 0;
    long long pos = 1; // starts at house 1

    for (int i = 0; i < m; i++) {
        long long nxt = a[i];
        if (nxt >= pos) time += (nxt - pos);
        else time += (n - pos) + nxt; // wrap around
        pos = nxt;
    }

    cout << time << "\n";
    return 0;
}