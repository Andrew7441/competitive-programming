#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1971/C Clocks and Strings

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        string s; 
        for(int i = 1; i <= 12; i++){
            if(i == a or i == b) s+= 'a';
            if(i == c or i == d) s+= 'b';
        }

        cout << (s == "abab" or s == "baba" ? "YES" : "NO") << endl;
    }

    return 0;
}