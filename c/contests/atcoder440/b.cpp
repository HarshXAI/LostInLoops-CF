#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].first;
        v[i].second = i+1;
}
sort(v.begin(), v.end());

    cout << v[0].second << " " << v[1].second << " " << v[2].second << endl;
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