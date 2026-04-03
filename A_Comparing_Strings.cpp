#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve() {
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        no;
        return;
    }

    vector<int> diff;

    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != b[i]) diff.push_back(i);
    }

    if (diff.size() != 2) {
        no;
        return;
    }

    int i = diff[0], j = diff[1];

    if (a[i] == b[j] && a[j] == b[i]) yes;
    else no;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}