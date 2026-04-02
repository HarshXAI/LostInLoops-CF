#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; 
    ll k;
    cin >> n >> k;
    vector<int> v(n*n);
    for(int i=0;i <n*n;i++) cin>> v[i];
    ll m=0;
    int s = 0, e = n*n-1;
    while(s<e){
        if(v[s] != v[e]) m++;
        s++;
        e--;
    }
    if(m >k) cout << "NO\n";
    else {
        if(n%2 != 0 || (k-m) %2 ==0) cout << "YES\n";
        else cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    
    }
    return 0;
}