#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >>n;
    vector<pair<int, int>> a(n);
    for ( int i=0; i< n; i++){
        cin>> a[i].first;
        a[i].second =i;
    }
    sort(a.begin(), a.end());
    vector<ll> prefix(n);
    prefix[0]= (ll)a[0].first;
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+(ll)a[i].first;
    }
    vector<int> ans(n);
    for(int i=n-1; i>=0 ; i--){
        if(i==n-1){
            ans[i]=n-1;
        }
        else{
            if (prefix[i] >=a[i+1].first){
                ans[i] = ans[i+1];
            }
            else{
                ans[i]=i;
            }
        }
    }

    vector<int> final_ans(n);
    for(int i=0;i < n;i++){
        final_ans[a[i].second]=ans[i];
    }
    for(int i=0;i <n;i++){
        cout<< final_ans[i]<< (i==n-1 ? "":" ");
        
    }
    cout <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // Fast I/O
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}