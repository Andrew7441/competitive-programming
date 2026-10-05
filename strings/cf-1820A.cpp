// Codeforces 1820A — Yura's New Name
// https://codeforces.com/problemset/problem/1820/A
// Topic: strings | Tags: greedy
// Complexity (yours): O(|s|) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve() {
    string s;
    cin >> s;

    if (s == "^") {
        cout << 1 << '\n';
        return;
    }

    int ans = 0;

    if (s.front() == '_') ans++;
    if (s.back() == '_') ans++;

    for (int i = 0; i + 1 < (int)s.size(); i++) {
        if (s[i] == '_' && s[i + 1] == '_') ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}

/*
💭 First Idea: Count fixes: leading '_', trailing '_', each "__" pair; special-case s == "^".
🧩 Key Property / Invariant: Every '_' needs a '^' directly on both sides; a single '^' needs a partner.
✅ Key insight: Each missing '^' is forced and independent: front, back, and between two adjacent '_'.
🔁 Recognition cue for next time: 'Minimum insertions so each char is in a pattern' -> count forced gaps locally.
⏱  Speed fix for next time: Handle n == 1 edge cases ('^' -> 1, '_' -> 2 falls out of the general rule) first.
🛠  Review: correct; Already optimal (verified vs BFS brute force on all strings up to length 6).
*/
