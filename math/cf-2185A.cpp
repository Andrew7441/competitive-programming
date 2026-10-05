// Codeforces 2185A — Perfect Root
// https://codeforces.com/problemset/problem/2185/A
// Topic: math | Tags: constructive
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cout << i << (i < n ? ' ' : '\n');
        }
    }
    return 0;
}

/*
💭 First Idea: Print 1..n — every positive integer x is the root of y = x*x.
🧩 Key Property / Invariant: Any x <= 10^9 works because x*x is an integer.
✅ Key insight: The definition is satisfied by every positive integer, so any n distinct small numbers are valid.
🔁 Recognition cue for next time: "Output any n distinct numbers with property P" where P is always true -> print 1..n.
⏱  Speed fix for next time: Check whether the property is trivially satisfied before overthinking.
🛠  Review: correct; O(n) -> Already optimal.
*/
