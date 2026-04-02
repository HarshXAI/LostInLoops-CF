#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Factors nikalne ka sahi tareeka
vector<int> get_factors(int n){
    vector<int> f;
    // i=1 se start karo, 0 se nahi!
    for(int i=1; i*i <= n; i++){
        if(n % i == 0){
            f.push_back(i);
            if(i*i != n){
                f.push_back(n/i);
            }
        }
    }
    return f;
}

void solve (){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i < n; i++) cin >> a[i];

    // Prefix sum (1-based index zyada easy rehta hai range sum ke liye)
    vector<ll> ps(n + 1, 0);
    for(int i=0; i < n; i++){
        ps[i+1] = ps[i] + a[i];
    }

    vector<int> facts = get_factors(n);
    ll ans = 0;

    for(int k : facts){
        if(k == n) continue; // Ek truck wala case skip

        ll cur_min = -1, cur_max = -1;

        // k-k ke blocks mein trucks ka weight nikaalo
        for(int j = k; j <= n; j += k){
            // Range (j-k to j) ka sum
            ll truck_weight = ps[j] - ps[j-k];

            if(cur_min == -1 || truck_weight < cur_min) cur_min = truck_weight;
            if(cur_max == -1 || truck_weight > cur_max) cur_max = truck_weight;
        }
        ans = max(ans, cur_max - cur_min);
    }
    cout << ans << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t;
    cin >> t;
    while(t--){
        solve(); // Yahan solve() call hoga
    }
    return 0;
}