#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

void solve() {
    int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for( int i=0; i<n;i++){
            cin>> a[i];
        }
        for( int i=0; i<n;i++){
            cin>> b[i];
        }

        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        int chalechalo=0;
        ll ans=1;
        for(int i=0;i <n;i++){
            while (chalechalo < n && a[chalechalo] >b[i])
            {
                chalechalo++;
            }
            ll something = chalechalo-i;
            if(something <=0){
                ans =0;
                break;
            }
            ans  = (ans*something) % MOD;
        }

        cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}