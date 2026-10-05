// Codeforces 2244A — Iskander and Drawings
// https://codeforces.com/problemset/problem/2244/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int longest = 0, current = 0;

    for(char& c : s){
        if(c == '#'){
            current++;
            longest = max(longest, current);
        }
        else {
            current = 0;
        }
    }

    cout << (longest + 1) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

/*
💭 First Idea: Find the longest run of "#"; erasing from both ends takes ceil(len / 2) seconds.
🧩 Key Property / Invariant: Each second removes one cm from each end of a line, i.e. 2 cm per second (1 for the last cm of an odd line).
✅ Key insight: The slowest line is the longest one, so answer = (longest + 1) / 2 (0 if there are no lines).
🔁 Recognition cue for next time: "Erase from both ends simultaneously" -> ceil(length / 2).
⏱ Speed fix for next time: Track the current run length in one pass.
🛠  Review: correct; O(n) -> Already optimal.
*/