#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    
    // 3 stacks, har ek mein n elements
    vector<vector<int>> stacks(3, vector<int>(n));
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> stacks[i][j];
        }
    }

    int curr_knowledge = 0;

    // Har stack par ek-ek karke jao
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            int book_v = stacks[i][j];
            
            // Subset check: Kya ye book safe hai?
            if ((book_v | x) == x) {
                curr_knowledge |= book_v;
            } else {
                // Agar illegal book mili, toh is stack mein aage nahi ja sakte
                break; 
            }
        }
    }

    if (curr_knowledge == x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;  
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}