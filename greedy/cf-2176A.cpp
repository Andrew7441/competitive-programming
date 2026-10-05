// Codeforces 2176A — Operations with Inversions
// https://codeforces.com/problemset/problem/2176/A
// Topic: greedy | Tags: arrays
// Complexity (yours): O(n) time, O(n) space
// Note: File was named 2176B but the code solves CF 2176A (Operations with Inversions); 2176B is Optimal Shifts. Correct, already optimal.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int pref_max = a[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (pref_max > a[i]) ++ans;        
            pref_max = max(pref_max, a[i]);
        }

        cout << ans << '\n';
    }
    return 0;
}

/*
💭 First Idea: Count elements smaller than the prefix maximum before them.
🧩 Key Property / Invariant: The prefix maximum can delete every smaller later element and is never deleted itself.
✅ Key insight: Answer = #i with max(a_1..a_{i-1}) > a_i; prefix maxima can never be removed.
🔁 Recognition cue for next time: "Remove a_j if some earlier a_i > a_j" -> prefix maximum.
⏱  Speed fix for next time: Single pass with a running max.
🛠  Review: correct (stress-tested vs brute force); O(n) -> Already optimal.
*/
