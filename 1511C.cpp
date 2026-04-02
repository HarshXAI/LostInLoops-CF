#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {

    int n, x;
    cin >>n>>x;
    vector<int> first_pos(51,-1);
    for(int i=1; i <=n;i++){
        int cd;
        cin >>cd;
        if(first_pos[cd]==-1) first_pos[cd] =i;
        else{
            if(first_pos[cd] > i) first_pos[cd] = i;
        } 
    }
    for(int i=0;i<x;i++){
        int t;cin >>t;
        int tidx = first_pos[t];
        cout << tidx << (i == x - 1 ? "" : " ");
        for(int j=1;j<=50;j++){
            if(first_pos[j]!=-1 && first_pos[j]<tidx){
                first_pos[j]++;
            }
        }
        first_pos[t] =1;
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T = 1;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}