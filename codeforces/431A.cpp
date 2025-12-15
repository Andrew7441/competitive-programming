#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/431/A Black Square

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string s;
    cin >> s;

    int res = 0;



    for(size_t i = 0; i < s.length(); i++){
        if(s[i] == '1') res += a;
        if(s[i] == '2') res += b;
        if(s[i] == '3') res += c;
        if(s[i] == '4') res += d;
    }
    cout << res;


    return 0;
}