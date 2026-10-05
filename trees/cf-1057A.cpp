// Codeforces 1057A — Bmail Computer Network
// https://codeforces.com/problemset/problem/1057/A
// Topic: trees | Tags: arrays
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<int> res; 

    for(int i = 2; i <= n; i++) cin >> p[i];

    for(int cur = n; cur != 1; cur = p[cur]){
        res.push_back(cur);
    }

    res.push_back(1);
    reverse(res.begin(), res.end());

    for(int i : res) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
💭 First Idea: Follow parent pointers from n up to 1, then reverse the path.
🧩 Key Property / Invariant: p_i < i, so the parent chain from n strictly decreases and ends at the root 1.
✅ Key insight: Path to root in a parent-array tree = repeatedly cur = p[cur].
🔁 Recognition cue for next time: "Given parent of each node, print path root→x" → walk up and reverse.
⏱ Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/