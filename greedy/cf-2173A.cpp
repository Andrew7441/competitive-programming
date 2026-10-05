// Codeforces 2173A — Sleeping Through Classes
// https://codeforces.com/problemset/problem/2173/A
// Topic: greedy | Tags: strings, implementation
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int x = 0;
    int res = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '1')
            x = k;
        else if(s[i] == '0' && x > 0){
            x--;
        }else if(s[i] == '0' && x <= 0){
            res++;
        }
    }

    cout << res << "\n";
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
💭 First Idea: Scan with a countdown: an important class resets it to k; a '0' is slept only when the countdown is 0.
🧩 Key Property / Invariant: You are forced awake only by the most recent important class within k positions.
✅ Key insight: Count '0's that are more than k positions after the last '1'.
🔁 Recognition cue for next time: "After an event, forced state for the next k steps" -> countdown / last-seen index.
⏱  Speed fix for next time: Store the last '1' index and test i - last > k.
🛠  Review: correct; O(n) -> Already optimal.
*/
