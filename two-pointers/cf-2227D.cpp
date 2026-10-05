// Codeforces 2227D — Palindromex
// https://codeforces.com/problemset/problem/2227/D
// Topic: two-pointers | Tags: brute-force, math
// Complexity (yours): — (unfinished: only reads input)
// ⚠️ Review: solve() reads the array but never computes or prints an answer; see corrected version below.
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int>a(2*n);
    for(int& i : a) cin >> i;

    
    
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
// O(n): expand around every center; each value appears twice, so each matching pair belongs to one center.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n; cin >> n;
    int m = 2 * n;
    vector<int> a(m);
    for (int &x : a) cin >> x;
    vector<char> seen(n + 2, 0);
    int best = 0;
    for (int c = 0; c < 2 * m - 1; c++) {      // centers: elements (c even) and gaps (c odd)
        int l = c / 2, r = (c + 1) / 2;
        vector<int> vals;
        if (l == r) { vals.push_back(a[l]); l--; r++; }
        while (l >= 0 && r < m && a[l] == a[r]) { vals.push_back(a[l]); l--; r++; }
        if (vals.empty()) continue;
        for (int x : vals) seen[x] = 1;        // maximal palindrome at this center has the largest mex
        int mex = 0;
        while (seen[mex]) mex++;
        best = max(best, mex);
        for (int x : vals) seen[x] = 0;
    }
    cout << best << "\n";
}
}

/*
💭 First Idea: (unfinished) — only the input is read.
🧩 Key Property / Invariant: A matched pair a[l] == a[r] uses both copies of that value, so it can only be matched for the center (l + r) / 2.
✅ Key insight: Expanding around all 4n-1 centers costs O(n) total; the maximal palindrome per center contains every smaller one, so take its mex.
🔁 Recognition cue for next time: "Palindromic subarray" + "each value appears exactly twice" -> center expansion is linear overall.
⏱  Speed fix for next time: Bound the total work of naive center expansion with a counting argument before reaching for Manacher.
🛠  Review: unfinished; optimized O(n) added, stress-tested vs brute force over all subarrays.
*/