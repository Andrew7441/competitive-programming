// Codeforces 2179A — Blackslex and Password
// https://codeforces.com/problemset/problem/2179/A
// Topic: math | Tags: strings
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int k, x;
        cin >> k >> x;

        cout << k * x + 1 << "\n";

    }

    return 0;
}

/*
💭 First Idea: Answer = k * x + 1.
🧩 Key Property / Invariant: Positions in the same residue class mod x must all differ, so each class holds at most k positions.
✅ Key insight: Max valid length is k*x, so the first impossible length is k*x + 1.
🔁 Recognition cue for next time: "Pairs with difference divisible by x must differ" -> split indices by residue mod x (pigeonhole).
⏱  Speed fix for next time: Go straight to residue classes.
🛠  Review: correct; O(1) -> Already optimal.
*/
