// Codeforces 2241B — Good times Good times
// https://codeforces.com/problemset/problem/2241/B
// Topic: constructive | Tags: math
// Complexity (yours): O(log x) time, O(1) space
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**/

void solve(){
    ll x;
    cin >> x;

    ll d = to_string(x).size();

    int y = 1;

    for(int i = 0; i < d; i++) y *= 10;
    y++;

    cout << y << "\n";
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
💭 First Idea: y = 10^d + 1 where d = number of digits of x.
🧩 Key Property / Invariant: x * (10^d + 1) writes x twice side by side, so its digit set equals x's.
✅ Key insight: y = 100...01 uses digits {0, 1} and x*y is "xx", both have at most two distinct digits.
🔁 Recognition cue for next time: "Keep the digit set when multiplying" -> multiply by 10^d + 1 to concatenate the number with itself.
⏱  Speed fix for next time: Remember the concatenation trick x * (10^d + 1).
🛠  Review: correct; O(log x) -> Already optimal (x < 1e8 so y <= 1e8+1 fits in int; property checked on random inputs).
*/
