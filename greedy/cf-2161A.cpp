// Codeforces 2161A — Round Trip
// https://codeforces.com/problemset/problem/2161/A
// Topic: greedy | Tags: implementation
// Complexity (yours): O(1) (stub: reads R, X, D, n only; never reads the string)
// ⚠️ Review: unfinished stub (does not read the string or print anything); see corrected version below.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int r, X, D, N;
        cin >> r >> X >> D >> N;

        
    }

    return 0;
}

// ===================== ⚡ Optimized =====================
// Finishes the stub. Greedy: a lower rating is never worse (div.1 is always rated, div.2 needs R < X),
// so after every rated round drop the rating as far as allowed: R = max(0, R - D).
// To submit: replace the body of your while(t--) loop with optimized::solve().
namespace optimized {
void solve() {
    long long R, X, D;
    int n;
    cin >> R >> X >> D >> n;
    string s;
    cin >> s;
    int rated = 0;
    for (char c : s) {
        if (c == '1' || R < X) {
            rated++;
            R = max(0LL, R - D);
        }
    }
    cout << rated << "\n";
}
}

/*
💭 First Idea: (not written) Only the first input line is read; string and answer are missing.
🧩 Key Property / Invariant: A lower rating is never worse: div.1 is always rated, div.2 only when R < X.
✅ Key insight: After every rated round lower the rating by the full D (not below 0) and count rated rounds.
🔁 Recognition cue for next time: "Choose a change in [-D, D] to maximise future chances" -> benefit is monotone -> always take the extreme.
⏱  Speed fix for next time: Read the whole input (the string!) first, then write the greedy loop.
🛠  Review: unfinished (stub); -> optimized O(n) greedy (stress-tested vs DP brute force).
*/
