#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // 1. Read number of test cases
    while(t--) {
        int n;
        cin >> n; // 2. Read length of string
        string s;
        cin >> s;
        
        bool found = false; // Flag to check if we found an answer
        
        // 3. Loop runs up to n-1 to avoid accessing memory outside the string
        for(int i = 0; i < n - 1; i++) {
            // Check if current char is greater than the next one
            if (s[i] > s[i+1]) {
                cout << "YES" << endl;
                // 4. Output 1-based indices (i+1 and i+2)
                cout << i + 1 << " " << i + 2 << endl;
                found = true;
                break; // We found it, stop the loop!
            }
        }
        
        // 5. If loop finished and we found nothing, print NO
        if (!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}