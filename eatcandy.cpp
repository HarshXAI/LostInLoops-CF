#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    int l = 0, r = n - 1;
    ll alice_sum = 0, bob_sum = 0;
    int max_candies = 0;

    while (l <= r) {
        if (alice_sum <= bob_sum) {
            alice_sum += ar[l];
            l++;
        } else {
            bob_sum += ar[r];
            r--;
        }

        if (alice_sum == bob_sum) {
            max_candies = l + (n - 1 - r);
        }
    }

    cout << max_candies << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}