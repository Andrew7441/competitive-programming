#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1850/A To My Critics

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b >= 10 or a + c >= 10 or b + a >= 10 or b + c >= 10 or 
        c + a >= 10 or c + b >= 10){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}