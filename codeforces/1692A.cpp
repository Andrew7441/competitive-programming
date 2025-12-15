#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1692/A Marathon

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 

    while(t--){
        int res = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a < b) res++;
        if(a < c) res++;
        if(a < d) res++;
        
        cout << res << endl;
    }

    return 0;
}