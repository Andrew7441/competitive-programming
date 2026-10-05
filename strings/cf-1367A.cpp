// Codeforces 1367A — Short Substrings
// https://codeforces.com/problemset/problem/1367/A
// Topic: strings
// Complexity (yours): O(|b|) time, O(|b|) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1367/A Short Substrings

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string b;
        cin >> b;

        string res = "";


        res += b[0];
        for(size_t i = 1; i < b.length(); i+=2){
            res += b[i];
        }
        cout << res << endl;

    }


    return 0;
}

/*
💭 First Idea: Take b[0] then every character at odd indices.
🧩 Key Property / Invariant: b is the concatenation of overlapping pairs, so consecutive pairs share one character.
✅ Key insight: a = b[0] + b[1] + b[3] + b[5] + ...
🔁 Recognition cue for next time: Overlapping windows glued together → take one char per window.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/
