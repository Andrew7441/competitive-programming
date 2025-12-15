#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/151/A  Soft Drinking

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int totaldrink = k * l;
    int totalslice = c * d;

    int toastsfromdrink = totaldrink / nl;
    int toastsfromlime = totalslice;
    int toastsfromsalt = p/np;

    int max_toasts = min({toastsfromdrink, toastsfromlime, toastsfromsalt});

    cout << max_toasts / n;





    return 0;
}