// Codeforces 2110A — Fashionable Array
// https://codeforces.com/problemset/problem/2110/A
// Topic: math | Tags: sorting, greedy
// Complexity (yours): O(n log n) time, O(n) space
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    if (x[0] % 2 == x[n - 1] % 2) {
        cout << 0 << endl;
        return;
    }
    int left = n, right = n;
    for (int i = 1; i < n; ++i) {
        if (x[i] % 2 != x[0] % 2) {
            left = i;
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (x[n - i - 1] % 2 != x[n - 1] % 2) {
            right = i;
            break;
        }
    }
    cout << min(left, right) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*
💭 First Idea: Sort; if min and max share parity answer 0, else strip the smallest up to the first other-parity element, or the largest likewise; take the smaller.
🧩 Key Property / Invariant: min+max is even iff min and max have the same parity.
✅ Key insight: Only removing from the ends of the sorted array changes min/max, so compare 'strip from left' vs 'strip from right'.
🔁 Recognition cue for next time: "min + max divisible by 2" -> parity of the extremes after sorting.
⏱  Speed fix for next time: Two scans from both ends; no other cases exist.
🛠  Review: correct; O(n log n) -> Already optimal (n <= 50).
*/
