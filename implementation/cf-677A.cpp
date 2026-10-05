// Codeforces 677A — Vanya and Fence
// https://codeforces.com/problemset/problem/677/A
// Topic: implementation | Tags: arrays
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/677/A Vanya and Fence

int main() {
    

    int n , h; 
    cin >> n >> h;


    int res = 0; 

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        res += a>h ? 2 : 1;
    }

    cout << res; 

    return 0;
}

/*
💭 First Idea: Add 2 for each friend taller than h, else 1.
🧩 Key Property / Invariant: Each person contributes independently.
✅ Key insight: Width = n + (# of a_i > h).
🔁 Recognition cue for next time: Independent per-element cost → single pass sum.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/
