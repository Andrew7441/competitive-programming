// Codeforces 1409A — Yet Another Two Integers Problem
// https://codeforces.com/problemset/problem/1409/A
// Topic: math | Tags: greedy
// Complexity (yours): O(1) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        cout << (abs(a-b) + 9) / 10 << "\n";


    }

    return 0;
}

/*
💭 First Idea: ceil(|a − b| / 10) via (|a − b| + 9) / 10.
🧩 Key Property / Invariant: Each move changes a by at most 10.
✅ Key insight: Greedily use 10s, plus one move for the remainder if any.
🔁 Recognition cue for next time: Min moves with step ≤ k → ceil(dist / k).
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(1) — Already optimal.
*/
