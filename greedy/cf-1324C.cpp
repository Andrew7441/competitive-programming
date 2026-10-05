// Codeforces 1324C — Frog Jumps
// https://codeforces.com/problemset/problem/1324/C
// Topic: greedy | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int last = 0, ans = 0;

    for(size_t i = 0; i < s.size(); i++){
        if(s[i] == 'R'){
            int position = i + 1;
            ans = max(ans, position - last);
            last = position;
        }
    }

    ans = max(ans, (int)s.size() + 1 - last);
    cout << ans << '\n';
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
💭 First Idea: Answer = largest gap between consecutive 'R' positions (with sentinels 0 and n+1).
🧩 Key Property / Invariant: Jumping left is never useful; the frog only ever needs to land on 'R' cells.
✅ Key insight: Minimal d = max distance between consecutive R's including start (0) and end (n+1).
🔁 Recognition cue for next time: "Minimum max jump" with forced directions → max gap between allowed landing spots.
⏱ Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/