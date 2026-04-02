#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i; 
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int last_pos = -1;
    bool possible = true;

    for (int i = 0; i < n; i++) {

        if (i == 0 || a[i] != a[i - 1]) {
            int current_source_pos = pos[a[i]];
            if (current_source_pos < last_pos) {
                possible = false;
                break;
            }
            last_pos = current_source_pos;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}