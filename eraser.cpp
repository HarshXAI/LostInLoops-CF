#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        ll ans = 0;
        set<char> charset;

        for(int i = 0; i < n; i++) { // 0-based index
            // Agar ye character pehli baar dikha hai
            if(charset.count(s[i]) == 0) {
                charset.insert(s[i]); // Isse mark karlo ki dekh liya
                
                // Is character se start hone wali total unique strings
                // hogi: (bacha hua suffix length)
                ans += (n - i); 
            }
        }
        cout << ans << endl;
    }
    return 0;
}