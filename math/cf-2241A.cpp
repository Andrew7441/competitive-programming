// Codeforces 2241A — Divide and Conquer
// https://codeforces.com/problemset/problem/2241/A
// Topic: math | Tags: number-theory
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int x,y;
    cin >> x >> y;

    if(x % y == 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

/*
💭 First Idea: YES iff y divides x.
🧩 Key Property / Invariant: x / z always divides x, so every reachable value is a divisor of x.
✅ Key insight: Any divisor y is reached in one step with z = x / y.
🔁 Recognition cue for next time: "Divide by any divisor repeatedly" -> reachable set = divisors.
⏱  Speed fix for next time: One modulo check.
🛠  Review: correct; O(1) -> Already optimal (matches samples).
*/
