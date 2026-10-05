// Codeforces 2134C — Even Larger
// https://codeforces.com/problemset/problem/2134/C
// Topic: greedy | Tags: arrays, implementation
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll ans = 0;
    ll previousOdd = 0;

    for (int i = 1; i <= n; i += 2) {
        ll keep = a[i];

        if (i > 1) {
            keep = min(keep, a[i - 1] - previousOdd);
        }

        if (i < n) {
            keep = min(keep, a[i + 1]);
        }

        ans += a[i] - keep;
        previousOdd = keep;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}

/*
💭 First Idea: Greedy left to right over odd positions: lower a[i] so it fits under both even neighbours.
🧩 Key Property / Invariant: The all-subarrays condition reduces to: every even-indexed a_i >= a_{i-1} + a_{i+1} (and >= a single odd neighbour).
✅ Key insight: Only decrease odd-indexed elements; keep each as large as allowed: min(a_i, a_{i+1}, a_{i-1} - kept_{i-2}).
🔁 Recognition cue for next time: "Every subarray satisfies a sum inequality" -> find the minimal windows (length 2/3) that imply all others.
⏱  Speed fix for next time: Prove the reduction to short windows first; then it is one greedy pass.
🛠  Review: correct (stress-tested vs brute force); O(n) -> Already optimal.
*/
