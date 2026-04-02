#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        vector<ll> a(n);
        vector<ll> ps(n+1,0);

        for(int i=0;i<n;i++) cin >> a[i];

        sort(a.begin(),a.end());

        for(int i=0;i <n;i++){
            ps[i+1]= ps[i]+a[i];
        }
        ll ans =0;
        for(int i=0; i<=k;i++){
            int left = 2*i;
            int right = k-i;

            ll idhar = ps[n-right] - ps[left];
            ans = max(idhar, ans);

        }
        cout << ans << endl;

    }
}