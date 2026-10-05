// Codeforces 2189A — Table with Numbers
// https://codeforces.com/problemset/problem/2189/A
// Topic: greedy | Tags: math
// Complexity (yours): — (empty stub)
// ⚠️ Review: solve() is empty and main never reads input; see corrected version below.
#include <bits/stdc++.h>
using namespace std;

void solve(){
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

// ===================== ⚡ Optimized =====================
// O(n): count numbers that can be a row (<= min(h,l)) and numbers that can only be a column.
// To submit: replace your solve() with this one and call it t times from main.
namespace optimized {
void solve() {
    int n, h, l;
    cin >> n >> h >> l;
    if (h > l) swap(h, l);                 // now h <= l
    int both = 0, colOnly = 0;             // both: usable as row or column; colOnly: only as column
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a <= h) both++;
        else if (a <= l) colOnly++;
    }
    // each counted pair needs one number <= h plus any other usable number
    cout << min(both, (both + colOnly) / 2) << "\n";
}
}

/*
💭 First Idea: (stub) — nothing implemented yet.
🧩 Key Property / Invariant: A pair (x, y) adds 1 only if x <= h and y <= l (or swapped); every useful pair has one number <= min(h, l).
✅ Key insight: With h <= l: answer = min(#a_i <= h, floor(#a_i <= l / 2)).
🔁 Recognition cue for next time: "Pair up items, each pair needs one of type A and one of type A-or-B" -> min(countA, total/2).
⏱  Speed fix for next time: Classify each number by which bound it fits, then take a min of counts.
🛠  Review: unfinished (empty stub); optimized O(n) added, stress-tested against brute-force pairing.
*/
