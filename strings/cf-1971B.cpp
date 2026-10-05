// Codeforces 1971B — Different String
// https://codeforces.com/problemset/problem/1971/B
// Topic: strings | Tags: sorting, constructive
// Complexity (yours): O(n log n) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        string res = s;
        sort(res.begin(), res.end());

        if(res == s) reverse(res.begin(), res.end());

        if(res == s) cout << "NO\n";
        else cout << "YES\n" << res << "\n";
    }

    return 0;
}

/*
💭 First Idea: Sort the string; if unchanged, reverse it; if still unchanged -> NO.
🧩 Key Property / Invariant: A different rearrangement exists iff the string has at least 2 distinct letters.
✅ Key insight: Sorted and reverse-sorted differ unless all chars are equal, so one of them != s.
🔁 Recognition cue for next time: "Any rearrangement different from s" -> try sorted / reversed / one swap.
⏱  Speed fix for next time: Alternative O(n): find any i with s[i] != s[0] and swap s[0], s[i].
🛠  Review: correct; Already optimal for |s| <= 10.
*/
