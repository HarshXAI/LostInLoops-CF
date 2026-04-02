#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i; return is;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < v.size(); i++) os << (i > 0 ? " " : "") << v[i];
    return os;
}

void solve() {
    int n,k ; cin >> n>>k;
    int trapped = n*n-k;
    if(trapped ==1 || trapped ==2 || trapped ==3){
        cout << "NO"<< endl;
        return;
    }
    cout << "YES"<< endl;
    vector<string> mat(n, string(n, 'U'));
    if (trapped ==0){
        for(auto &s : mat) cout << s << endl;
        return;
    }
    int curr_trap=4;
    mat[n-2][n-2]='R'; mat[n-2][n-1]='D';
    mat[n-1][n-1]='U'; mat[n-1][n-1]='L';
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            // Agar ye cell 2x2 cycle ka hissa hai, skip karo
            if ((i >= n-2) && (j >= n-2)) continue;

            if (curr_trap < trapped) {
                // Is cell ko kisi trapped cell ki taraf point karao
                if (i + 1 < n) mat[i][j] = 'D'; // Neeche trapped cell hai
                else if (j + 1 < n) mat[i][j] = 'R'; // Right mein trapped cell hai
                
                curr_trap++;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << mat[i] << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}