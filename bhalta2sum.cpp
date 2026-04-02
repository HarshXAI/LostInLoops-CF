#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    ll k;cin >>k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int i=0, j=1;
    while(i <n && j<n){
        ll diff = a[j]-a[i];
        if(diff == k && i!=j){
            cout <<"YES\n";
            return;
        }
        if(diff<k){
            j++;
        }
        else i++;
        if(i==j) j++;

    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}