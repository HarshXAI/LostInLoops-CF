#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll check(vector<int> &a, ll h){
    ll tv = 0;
    for(int i =0; i<a.size();i++){
        if( h> a[i]){

            tv+= h-a[i];
        }
    }
    
    return tv;

}

void solve(vector<int> &a, int vol) {
    ll v = vol;
    ll low = 1;
    ll high = 2e9 + 5;
    ll res= 1;
    while(low<= high){
        ll mid = low+(high-low) /2;
        if(check(a, mid) <= v){
            res = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }

    cout << res << endl;
    // cout << res << endl;

}

int main() {
    int t;
    cin >> t;
     while (t--)
     {
        int n , max_vol;
        cin >> n >> max_vol;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >>a[i];
        solve(a,max_vol);
     }
     
}