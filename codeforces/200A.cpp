#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/200/B Drinks

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n; 
    cin >> n;

    double res = 0;
    int p;
    for(int i = 0; i < n; i++){
        cin >> p;
        res += p;
    }
    cout << double(res/n) << endl;

    return 0;
}