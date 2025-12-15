#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1807/A Plus or Minus

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b == c){
            cout << "+\n";
        }else if(a - b == c){
            cout << "-\n";
        }
    }
    return 0;
}