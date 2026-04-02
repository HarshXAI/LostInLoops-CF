#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i; return is;
}

void solve() {
    int n, m, k; 
    cin >> n >> m >> k;
    vll robo(n), spk(m);
    cin >> robo >> spk;
    string s;
    cin >> s;
    
    sort(all(spk));

    vi L_time(k + 1, k + 1), R_time(k + 1, k + 1);
    int curr = 0, min_d = 0, max_d = 0;

    for (int i = 0; i < k; i++) {
        if (s[i] == 'L') curr--;
        else curr++;

        if (curr < min_d) {
            min_d = curr;
            int d = abs(min_d);
            if (d <= k) L_time[d] = min(L_time[d], i + 1);
        }
        if (curr > max_d) {
            max_d = curr;
            int d = max_d;
            if (d <= k) R_time[d] = min(R_time[d], i + 1);
        }
    }

    vi die_at(k + 2, 0);
    for (int i = 0; i < n; i++) {
        int t_death = k + 1;
        auto it = lower_bound(all(spk), robo[i]);

        if (it != spk.end()) {
            ll dist = *it - robo[i];
            if (dist <= k) t_death = min(t_death, R_time[dist]);
        }
        if (it != spk.begin()) {
            ll dist = robo[i] - *prev(it);
            if (dist <= k) t_death = min(t_death, L_time[dist]);
        }

        if (t_death <= k) die_at[t_death]++;
    }

    int alive = n;
    for (int i = 1; i <= k; i++) {
        alive -= die_at[i];
        cout << alive << (i == k ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}