// Codeforces 151A — Soft Drinking
// https://codeforces.com/problemset/problem/151/A
// Topic: math | Tags: implementation
// Complexity (yours): O(1) time, O(1) space
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

/*
💭 First Idea: Compute toasts from drink, lime and salt; take the min and divide by n.
🧩 Key Property / Invariant: The scarcest resource limits the total number of toasts.
✅ Key insight: answer = min(k*l/nl, c*d, p/np) / n.
🔁 Recognition cue for next time: 'Limited by several resources' -> min of each bound.
⏱  Speed fix for next time: Write the formula directly in one line.
🛠  Review: correct; Already optimal.
*/
