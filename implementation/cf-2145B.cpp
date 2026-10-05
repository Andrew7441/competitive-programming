// Codeforces 2145B — Deck of Cards
// https://codeforces.com/problemset/problem/2145/B
// Topic: implementation | Tags: greedy, strings
// Complexity (yours): O(n + k) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = count(s.begin(), s.end(), '1');
    int cnt2 = count(s.begin(), s.end(), '2');

    string ans(n, '+');

    for(int i = 0; i < n; i++){
        if(i < cnt0 + cnt2 || i >= n - cnt1 - cnt2) ans[i] = '?';
        if(i < cnt0 || i >= n - cnt1 || k == n) ans[i] = '-';
    }

    cout << ans << "\n";
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
💭 First Idea: Count 0s, 1s, 2s: the top cnt0 and bottom cnt1 cards are surely gone; the next cnt2 at each end are '?'.
🧩 Key Property / Invariant: Removed cards always form a prefix of length p plus a suffix of length k-p, with cnt0 <= p <= cnt0+cnt2.
✅ Key insight: Card i is '-' if i < cnt0 or i >= n-cnt1, '?' if within cnt2 more of either end, else '+'; k == n -> all '-'.
🔁 Recognition cue for next time: "Remove from top/bottom, some choices unknown" -> removed set is prefix + suffix; only counts matter.
⏱  Speed fix for next time: Handle k == n first (everything removed whatever the choices).
🛠  Review: correct (stress-tested vs brute force); O(n + k) -> Already optimal.
*/
