#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        b[i] = a[i] - (i+1);
    }
    while(q--){
        ll x,y;
        cin >> x >> y;
        ll indx_x = lower_bound(a.begin(),a.end() , x) - a.begin();
        ll k= (x-indx_x) +y-1;
        auto it = lower_bound(b.begin(), b.end(), k);
        int pos = it - b.begin();
        if (it == b.end()) {
            cout << a[n-1] + (k - b[n-1]) << "\n";
        } else {
            cout << a[pos] - (b[pos] - k + 1) << "\n";
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    // int t;
    // cin >>t;
    // while(t--){
        solve();
    // }
}