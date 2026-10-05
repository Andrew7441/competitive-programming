// Codeforces 1607A — Linear Keyboard
// https://codeforces.com/problemset/problem/1607/A
// Topic: hashing | Tags: strings
// Complexity (yours): O(26 + |s|) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string keyboard;
        cin >> keyboard;

        string s; 
        cin >> s;
        
        unordered_map<char, int> pos;
        for(int i = 1; i < 27;i++){
            pos[keyboard[i]] = i;
        }

        int res = 0;

        for(size_t i = 1; i < s.length(); i++){
            res += abs(pos[s[i-1]] - pos[s[i]]);
        }

        cout << res << "\n";

    }

    return 0;
}

/*
💭 First Idea: Store each key's position, sum |pos[s[i−1]] − pos[s[i]]|.
🧩 Key Property / Invariant: Distance only depends on key positions.
✅ Key insight: Precompute letter→position, then one pass over s.
🔁 Recognition cue for next time: "Cost depends on char positions" → position lookup table.
⏱  Speed fix for next time: Loop i=1..26 reads keyboard[26]=='\0' and leaves keyboard[0] at map default 0 — correct by accident; loop i=0..25 and use int pos[26].
🛠  Review: correct; O(|s|) — Already optimal.
*/
