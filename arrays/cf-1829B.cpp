// Codeforces 1829B — Blank Space
// https://codeforces.com/problemset/problem/1829/B
// Topic: arrays | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
// Note: file was named 1829A, but this code solves 1829B (Blank Space).
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
        
        int res = 0;
        int var = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a == 0){
                res++;
                var = max(res, var);
            }else{
                res = 0;
            }
        }

        cout << var << endl;
    }

    return 0;
}

/*
💭 First Idea: Track the current run of zeros and keep the maximum.
🧩 Key Property / Invariant: Reset the run on every 1.
✅ Key insight: Longest run of equal values = one pass with a counter.
🔁 Recognition cue for next time: 'Longest consecutive segment of X' -> running counter + max.
⏱  Speed fix for next time: Use '\n' instead of endl inside the loop.
🛠  Review: correct; Already optimal. NOTE: file was named 1829A but this code solves 1829B (1829A is 'Love Story').
*/
