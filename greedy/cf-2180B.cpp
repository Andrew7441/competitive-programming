// Codeforces 2180B — Ashmal
// https://codeforces.com/problemset/problem/2180/B
// Topic: greedy | Tags: strings
// Complexity (yours): O(L^2) time (string insert at front), O(L) space
// ⚠️ Review: compares first letters of a[i] and a[i-1] instead of the whole candidates (a c b -> "bac", expected "acb"); see corrected version below.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string> a(n);

        for(string& i : a) cin >> i;

        string res = a[0];

        for(int i = 1; i < n; i++){
            if(a[i][0] >= a[i-1][0]){
                res += a[i];
            }else 
                res.insert(0, a[i]);
        }
        cout << res << "\n";
    }

    return 0;
}

// ===================== ⚡ Optimized =====================
// Fix: comparing first letters of a[i] and a[i-1] is not enough (e.g. "a c b" -> yours "bac", best "acb").
// Exchange argument: at each step keep the smaller of a_i + s and s + a_i. O(n * |s|) <= 4e6.
// To submit: replace the body of your while(t--) loop with optimized::solve().
namespace optimized {
void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        string front = x + s, back = s + x;
        s = min(front, back);
    }
    cout << s << "\n";
}
}

/*
💭 First Idea: Append a_i if its first letter >= the first letter of a_{i-1}, else prepend.
🧩 Key Property / Invariant: Only the current s matters, and the smaller of a_i + s and s + a_i stays smaller after any later additions on either side.
✅ Key insight: Greedy: s = min(a_i + s, s + a_i).
🔁 Recognition cue for next time: "Add to front or back, lexicographically smallest" -> compare both whole candidate strings.
⏱  Speed fix for next time: Compare against the whole current s, not the previous piece; test [a, c, b].
🛠  Review: wrong: compares a[i][0] with a[i-1][0] instead of with s (a c b -> 'bac', expected 'acb'); optimized O(n * L).
*/
