// Codeforces 1520A — Do Not Be Distracted!
// https://codeforces.com/problemset/problem/1520/A
// Topic: strings | Tags: hashing
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; 
    cin >> n;

    string s;
    cin >> s;

    char prev = s[0];
    array<bool,26> finished{};


    for(int i = 1; i < n; i++){
        if(prev == s[i]) continue;

        finished[prev - 'A'] = true; 

        if(finished[s[i] - 'A']){
            cout << "NO\n";
            return;
        }
        prev = s[i];
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}

/*
💭 First Idea: Mark a letter finished when its block ends; seeing a finished letter again → NO.
🧩 Key Property / Invariant: Each letter's occurrences must form one contiguous block.
✅ Key insight: Track "seen and closed" letters while scanning blocks.
🔁 Recognition cue for next time: "Each task done in one go" → each char appears in a single contiguous run.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/
