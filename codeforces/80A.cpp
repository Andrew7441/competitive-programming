#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/80/A
// brute force

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,m;
    cin >> n >> m;

    if(n > m){
        cout << "NO\n";
        return 0;
    }

    if(n % n == 0 and m % m == 0){
        cout << "YES\n";
    }


    return 0;
}