#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1985/A Creating Words

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string a, b;
        cin >> a >> b;

        char temp = a[0];
        a[0] = b[0];
        b[0] = temp;

        cout << a << " " << b << endl;
    }

    return 0;
}