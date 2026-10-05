// Codeforces 2064A — Brogramming Contest
// https://codeforces.com/problemset/problem/2064/A
// Topic: greedy | Tags: strings
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        int n; cin >> n;

        string s; cin >> s;

        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i] != s[i+1]){
                ans++;
            }
        }
        if(s[0] == '1') ans++;

        cout << ans << "\n";
    }

    return 0;
}

/*
💭 First Idea: Answer = number of positions where s[i] != s[i+1], plus 1 if s starts with '1'.
🧩 Key Property / Invariant: Each move can fix one block boundary; the leading '1' block needs an extra move.
✅ Key insight: Count transitions (after prepending a virtual '0').
🔁 Recognition cue for next time: "Move suffixes between two strings to separate 0s and 1s" -> count block boundaries.
⏱  Speed fix for next time: Prepend '0' to s and just count s[i] != s[i+1].
🛠  Review: correct; Already optimal (verified vs BFS brute force).
*/
