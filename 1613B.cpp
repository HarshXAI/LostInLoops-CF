#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;cin >>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>> a[i];
    }
    int i = n-1;
    int count = 0;
    int ans=0;
    while(i>=0){
        if(a[i]==a[n-1]){
            count++;
            i--;
        }
        else{
            ans++;
            i-=count;
            count *=2;
        }
    }
    cout << ans << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}