// Codeforces 2125A — Difficult Contest
// https://codeforces.com/problemset/problem/2125/A
// Topic: strings | Tags: sorting, constructive
// Complexity (yours): O(n) time, O(1) space
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

        unordered_map<char, int> cnt;

        for(char i : s){
            cnt[i]++;
        }

        string newstr = "";
        for(auto &p : cnt){
            if(p.first != 'T') continue;
            cout << string(p.second, p.first);
        }

        for(auto &p : cnt){
            if(p.first != 'T'){
                cout << string(p.second, p.first);
            }
        }
        cout << '\n';
    }
    return 0;
}

/*
💭 First Idea: Count letters, print all 'T's first, then everything else.
🧩 Key Property / Invariant: Both FFT and NTT end in 'T'; if every T precedes every other letter, no T has an F or N before it.
✅ Key insight: Put all T's at the front (plain descending sort fails because letters > 'T' exist).
🔁 Recognition cue for next time: "Rearrange to avoid patterns" -> look at what all patterns share (here the final T).
⏱  Speed fix for next time: Count 'T' and print the remaining letters in original order; no map needed.
🛠  Review: correct; O(n) -> Already optimal.
*/
