#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> w, v;

int rec(int i, int remaining) {
    // base case
    if (i == n) return 0;

    // option 1: skip
    int not_take = rec(i + 1, remaining);

    // option 2: take (if possible)
    int take = 0;
    if (w[i] <= remaining) {
        take = v[i] + rec(i + 1, remaining - w[i]);
    }

    return max(take, not_take);
}

int main() {
    cin >> n >> W;

    w.resize(n);
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    cout << rec(0, W) << endl;
}