// Codeforces 2244B — Nikita and Books
// https://codeforces.com/problemset/problem/2244/B
// Topic: greedy | Tags: prefix-sum, math
// Complexity (yours): O(n) time, O(1) space
// ⚠️ Review: int minNeeded = k*(k+1)/2 overflows for k >= 65536 (n up to 2e5) and can print YES instead of NO; see corrected version below.
#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;

   long long prefSum = 0;
   bool possible = true;

   for(long long k = 1; k <= n; k++){
    int x;
    cin >> x;

    prefSum += x;

    int minNeeded = k * (k + 1) / 2;

    if(prefSum < minNeeded){
        possible = false;
    }
   }

   cout << (possible ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}


// ===================== ⚡ Optimized =====================
// Same O(n) idea; the only fix is computing k*(k+1)/2 in long long.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n; cin >> n;
    long long pref = 0;
    bool ok = true;
    for (long long k = 1; k <= n; k++) {
        long long x; cin >> x;
        pref += x;
        if (pref < k * (k + 1) / 2) ok = false;   // need b_i >= i, and moves only push books right
    }
    cout << (ok ? "YES\n" : "NO\n");
}
}

/*
💭 First Idea: Every prefix must hold at least 1 + 2 + ... + k books.
🧩 Key Property / Invariant: Moves only push books to the right, so prefix sums can only decrease; a strictly increasing b with b_1 >= 1 has b_i >= i.
✅ Key insight: Feasible iff prefix_k >= k(k+1)/2 for every k (push the surplus right greedily to get 1, 2, ..., n-1, rest).
🔁 Recognition cue for next time: "Move units only to the right, reach a strictly increasing array" -> compare prefix sums with 1 + 2 + ... + k.
⏱ Speed fix for next time: Keep every quantity derived from k or prefix sums in long long.
🛠  Review: wrong (int overflow on k*(k+1)/2 when n > 65535; a 70000-element test prints YES, expected NO); fixed version O(n), stress-tested vs BFS.
*/