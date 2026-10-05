// Codeforces 2193A — DBMB and the Array
// https://codeforces.com/problemset/problem/2193/A
// Topic: math | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, x;
    cin >> n >> s >> x;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        sum += v;
    }

    if (sum <= s && (s - sum) % x == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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
💭 First Idea: Sum the array; we can only add multiples of x, so need sum <= s and (s - sum) % x == 0.
🧩 Key Property / Invariant: Operations only increase the sum, in steps of exactly x.
✅ Key insight: Reachable sums are exactly sum + k*x for k >= 0.
🔁 Recognition cue for next time: "Add x to any element any number of times, hit total s" -> divisibility of the gap.
⏱  Speed fix for next time: Reduce to the total sum immediately — individual elements do not matter.
🛠  Review: correct; O(n) -> Already optimal.
*/
