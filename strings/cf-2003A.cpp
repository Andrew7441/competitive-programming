// Codeforces 2003A — Turtle and Good Strings
// https://codeforces.com/problemset/problem/2003/A
// Topic: strings | Tags: constructive
// Complexity (yours): O(n) per test
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

        string s;
        cin >> s;

        string t = s;

        if(s[0] == t[n-1]){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }


    return 0;
}

/*
💭 First Idea: YES iff s[0] != s[n-1] (the copy t is unnecessary).
🧩 Key Property / Invariant: If first != last, split into s[0] and s[1..]: first char of part1 != last char of part2.
✅ Key insight: Only the first and last characters matter.
🔁 Recognition cue for next time: "Split string so that first/last chars of parts differ" -> look at the string ends.
⏱  Speed fix for next time: Drop the unused copy t; compare s.front() and s.back().
🛠  Review: correct; Already optimal.
*/
