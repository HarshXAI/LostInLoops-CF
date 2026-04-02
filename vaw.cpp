#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int b[n];

    unordered_set<int> seen_elements;

    bool flag = false;

    for (int i = 0; i < n; i++) {
      cin >> b[i];
      seen_elements.insert(b[i]);
    }
    if (seen_elements.size() == n)
      cout << "NO" << endl;
    else 
      cout << "YES" << endl;
  }
}