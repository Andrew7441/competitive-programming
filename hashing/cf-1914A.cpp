// Codeforces 1914A — Problemsolving Log
// https://codeforces.com/problemset/problem/1914/A
// Topic: hashing | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    cin >> n;

    string s;
    cin >> s;

    vector<int> f(26,0);

    for(char &i: s){
        f[i-'A']++;
    }

    int solved = 0;
    for(int i = 0; i < 26; i++){
        if(f[i] >= i + 1) solved++;
    }

    cout << solved << "\n";
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
💭 First Idea: Count each letter; problem i is solved if cnt[i] >= i+1.
🧩 Key Property / Invariant: Problem 'A' needs 1 minute, 'B' 2, ..., 'Z' 26.
✅ Key insight: A frequency array over 26 letters solves it.
🔁 Recognition cue for next time: 'Letters as events, thresholds per letter' -> cnt[26].
⏱  Speed fix for next time: Correct as is.
🛠  Review: correct; Already optimal.
*/
