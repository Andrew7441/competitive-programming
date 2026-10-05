// Codeforces 2117A — False Alarm
// https://codeforces.com/problemset/problem/2117/A
// Topic: implementation | Tags: greedy
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;

        int l = 1e5, r = -1; 
        for(int i = 0; i < n; i++){
            int door;
            cin >> door;
            
            
            if(door == 1){
                l = min(l, i);
                r = max(r, i);
            }
        }

        cout << (x >= r - l + 1 ? "YES\n" : "NO\n");
    }


    return 0;
}

/*
💭 First Idea: Find the first and last closed door; press the button at the first one.
🧩 Key Property / Invariant: Pressing exactly at the first closed door is optimal; it must last until the last closed door.
✅ Key insight: YES iff last - first + 1 <= x.
🔁 Recognition cue for next time: "One-time power-up of fixed duration" -> span between first and last obstacle.
⏱  Speed fix for next time: Track first/last index while reading.
🛠  Review: correct; O(n) -> Already optimal.
*/
