#include<bits/stdc++.h>
using namespace std;

typedef long long ll; // Long long zaroori hai

void solve() {  
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    
    // City indices ko 0-indexed bana lo
    a--; b--; 

    vector<pair<ll, ll>> loc(n);
    for(int i=0; i<n; i++){
        cin >> loc[i].first >> loc[i].second;
    }

    // Direct distance between a and b
    ll direct_dist = abs(loc[a].first - loc[b].first) + abs(loc[a].second - loc[b].second);

    // Agar k=0 hai, toh koi major city nahi hai
    if (k == 0) {
        cout << direct_dist << endl;
        return;
    }

    ll mindistA = 4e18; // Bahut bada number
    ll mindistB = 4e18;

    // Major cities 0 se k-1 tak hain
    for (int i=0; i<k; i++){
        ll distA = abs(loc[a].first - loc[i].first) + abs(loc[a].second - loc[i].second);
        ll distB = abs(loc[b].first - loc[i].first) + abs(loc[b].second - loc[i].second);
        mindistA = min(mindistA, distA);
        mindistB = min(mindistB, distB);
    }

    // Final answer is either direct or via two major cities
    // Note: major to major distance 0 hai, isliye sirf A->Major + Major->B
    cout << min(direct_dist, mindistA + mindistB) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}