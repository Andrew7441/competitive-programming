#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1367/A Short Substrings

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string b;
        cin >> b;

        string res = "";


        res += b[0];
        for(size_t i = 1; i < b.length(); i+=2){
            res += b[i];
        }
        cout << res << endl;

    }


    return 0;
}