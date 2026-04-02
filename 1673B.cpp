#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    unordered_set<char> unique_chars;
    unordered_set<char> seen;
    
    for(char c : s) {
        unique_chars.insert(c);
    }
    int k = unique_chars.size();

    for(int i=0;i<k;i++){
        seen.insert(s[i]);
    }
    if(seen.size() < k){
        cout << "NO\n";
        return;
    }
    
    for(int i=k;i<s.size();i++){
        if(s[i]!=s[i-k]){
             cout << "NO\n";
             return;
        }
    }
    cout<<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while (t--)
    {
        solve();
    }
    
}