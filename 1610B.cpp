#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(vector<int> &a, int x ){
    int i = 0, j = a.size()- 1;
    while(i<j){
        if(a[i] == x)i++;
        else if (a[j] == x) j--;
        else if (a[i] != a[j]) return false;
        else{
            i++;
            j--;
        }
    }
    return true;
}

void solve() {
    int n;cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++)cin >>a[i];
    int left = -1, right= -1;
    int l=0,r=n-1;
    bool mismatch_found = false;
    while (l<r)
    {
        if (a[l] != a[r]) {
            left = a[l];
            right = a[r];
            mismatch_found = true;
            break;
        }
        l++;
        r--;
    }

    if(!mismatch_found){
        cout << "YES\n";
        return;
    }
    if (check(a, left) || check(a, right)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}