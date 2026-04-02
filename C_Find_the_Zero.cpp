#include <bits/stdc++.h>
using namespace std;

int ask(int i, int j) {
    cout << "? " << i << " " << j << '\n';
    cout.flush();

    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

void answer(int k) {
    cout << "! " << k << '\n';
    cout.flush();
}

void solve() {
    int n;
    cin >> n;

    if (n == 2) {
        if (ask(1, 2) == 1) {
            answer(1);
            return;
        }
        if (ask(2, 3) == 1) {
            answer(2);
            return;
        }
        if (ask(1, 3) == 1) {
            answer(1);
            return;
        }

        // All three are pairwise unequal, so among {1,2,3} at most one zero.
        // Total zeros = 2, hence index 4 must be zero.
        answer(4);
        return;
    }

    // n >= 3
    if (ask(1, 2) == 1) {
        answer(1);
        return;
    }
    if (ask(2, 3) == 1) {
        answer(2);
        return;
    }
    if (ask(1, 3) == 1) {
        answer(1);
        return;
    }

    if (ask(4, 5) == 1) {
        answer(4);
        return;
    }

    for (int i = 7; i <= 2 * n; i += 2) {
        if (ask(i, i + 1) == 1) {
            answer(i);
            return;
        }
    }

    // If all answers were 0:
    // triangle contributes at most 1 zero,
    // (4,5) contributes at most 1 zero,
    // each remaining queried pair contributes at most 1 zero.
    // Total among queried vertices = 1 + 1 + (n-3) = n-1.
    // But total zeros are n, so index 6 must be zero.
    answer(6);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}