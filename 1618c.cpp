#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// int gcd

void solve() {
    int n;cin >> n;
    vector<ll> og(n);
    for (int i = 0; i < n; i++)
    {
        cin>> og[i];
    }
    ll g1=og[0];
    ll g2=og[1];
    for(int i=0;i<n;i+=2){
        g1 = __gcd(g1,og[i]);
    }
    for(int i=1;i<n;i+=2){
        g2 = __gcd(g2,og[i]);
    }
    bool g1flag = true;
    bool g2flag = true;
    for(int i=0;i<n;i+=2){
        if(og[i]%g2 ==0){
            g2flag = false;
        }
    }
    for(int i=1;i<n;i+=2){
        if(og[i]%g1 ==0){
            g1flag = false;
        }
    }
    if(g1flag == true){
        cout << g1 << endl;
        return;
    }
    else if(g2flag == true){
        cout << g2 << endl;
        return;
    }
    else {
        cout <<0<<endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}