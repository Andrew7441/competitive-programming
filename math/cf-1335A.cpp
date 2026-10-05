// Codeforces 1335A — Candies and Two Sisters
// https://codeforces.com/problemset/problem/1335/A
// Topic: math
// Complexity (yours): O(1) per test
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/1335/A Candies and Two Sisters

int main() {

    int t;
    cin >> t; 

    while(t--){
        int n; 
        cin >> n;
        cout << (n - 1) / 2 << endl;
    }

    return 0;
}

/*
💭 First Idea: Count pairs a > b ≥ 1 with a + b = n: (n − 1) / 2.
🧩 Key Property / Invariant: b ranges over 1..⌈n/2⌉−1.
✅ Key insight: Closed form (n−1)/2 handles both parities.
🔁 Recognition cue for next time: Count splits with strict inequality → simple division formula.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(1) — Already optimal.
*/
