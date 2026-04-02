#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int open =0;
        int close =0;
        int ans=0;
        for (auto c:s){
            if(c == ')'){
                close++;
            }
            else{
                open++;
            }
            if (close>open){
                ans++;
                close--;
            }
            // cout<<"ans: " << ans <<endl;
        }
        cout << ans << endl;
    }
    return 0;
}