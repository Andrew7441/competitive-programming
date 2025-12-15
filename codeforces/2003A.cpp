#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        string t = s;

        if(s[0] == t[n-1]){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }


    return 0;
}