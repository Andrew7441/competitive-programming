// Codeforces 2193B — Reverse a Permutation
// https://codeforces.com/problemset/problem/2193/B
// Topic: greedy | Tags: constructive
// Complexity (yours): O(n^2) worst case time, O(1) space
// ⚠️ Review: max_element inside the while loop is O(n^2) (e.g. n, n-1, ..., 3, 1, 2 with n = 2e5 TLEs); see corrected version below.
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &x : p) cin >> x;

    int l = 0;
    while (l < n - 1 && p[l] >= *max_element(p.begin() + l, p.end())) l++;

    if (l < n - 1) {
        int r = l;
        int max_val = p[l];
        for (int i = l; i < n; i++) {
            if (p[i] >= max_val) {
                max_val = p[i];
                r = i;
            }
        }
        reverse(p.begin() + l, p.begin() + r + 1);
    }

    for (int x : p) cout << x << " ";
    cout << "\n";
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

// ===================== ⚡ Optimized =====================
// O(n) instead of O(n^2): in a permutation the correct prefix is n, n-1, ..., so no max_element needed.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n; cin >> n;
    vector<int> p(n), pos(n + 1);
    for (int i = 0; i < n; i++) { cin >> p[i]; pos[p[i]] = i; }
    int l = 0;
    while (l < n && p[l] == n - l) l++;     // prefix already n, n-1, ... is optimal
    if (l < n) reverse(p.begin() + l, p.begin() + pos[n - l] + 1);  // bring the largest missing value to l
    for (int x : p) cout << x << ' ';
    cout << "\n";
}
}

/*
💭 First Idea: Skip the prefix that is already maximal, then reverse from l up to the position of the largest remaining value.
🧩 Key Property / Invariant: Lexicographic max: fix the first position where p differs from n, n-1, ...; put the largest remaining value there.
✅ Key insight: For a permutation the value that must go to index l is exactly n - l; store positions to find it in O(1).
🔁 Recognition cue for next time: "One reversal, lexicographically max/min" -> first bad index l, reverse [l, pos of best value].
⏱  Speed fix for next time: Avoid recomputing max_element in a loop; for permutations the expected value is known (n - l).
🛠  Review: wrong (TLE) — logic is right but worst case O(n^2) with n = 2e5 (measured >10 s); optimized O(n), stress-tested vs brute force.
*/
