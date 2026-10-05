// Codeforces 2241C — RemovevomeR
// https://codeforces.com/problemset/problem/2241/C
// Topic: strings | Tags: greedy, constructive
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int runs = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) runs++;
    }

    int minwf = (runs == 2 ? 2 : 1);

    cout << minwf << '\n';
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
💭 First Idea: Count runs; answer 2 if there are exactly two runs, else 1.
🧩 Key Property / Invariant: Every palindrome in 0^a 1^b lies inside one run, so two runs can never merge (stuck at "01").
✅ Key insight: With 1 run shrink to 1; with >= 3 runs delete the middle of "x y x" to merge runs and keep going down to 1.
🔁 Recognition cue for next time: "Delete from a palindrome, minimize length" on binary strings -> look at the run structure.
⏱  Speed fix for next time: Brute-force tiny cases to spot that the answer is almost always 1.
🛠  Review: correct; O(n) -> Already optimal (verified by BFS brute force for n <= 9).
*/
