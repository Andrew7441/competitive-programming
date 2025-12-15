#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1999/A

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    
    while(t--){
        int res = 0;
        string s;
        int x;
        cin >> x;
        s = to_string(x);

        for(size_t i = 0; i < s.length();i++){
            res += s[i] - '0';
        }
        cout << res << endl;; 
    }


    return 0;
}