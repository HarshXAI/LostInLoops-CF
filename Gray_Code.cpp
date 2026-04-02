#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        int g = i ^ (i >> 1);
        bitset<16> b(g);
        string s = b.to_string();
        cout << s.substr(16 - n) << '\n';
    }

    return 0;
}

int fact( int n){
    if(n==0)return 1;
    return n*fact(n-1);
}