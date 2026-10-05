// Codeforces 750A — New Year and Hurry
// https://codeforces.com/problemset/problem/750/A
// Topic: implementation | Tags: math, brute-force
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int available = 240 - k;
    int total =  0;
    int res = 0;

    for(int i = 1; i <= n; i++){
        total += i * 5;
        if(total > available) break;
        res++;
    }

    cout << res << "\n";
    
    return 0;
}


/*
💭 First Idea: Add problem times 5·i cumulatively while within 240 − k minutes.
🧩 Key Property / Invariant: Solving problems in order 1..i is optimal since times increase.
✅ Key insight: Prefix of cheapest problems maximizes count.
🔁 Recognition cue for next time: "Max items within budget, costs increasing" → take prefix greedily.
⏱  Speed fix for next time: None needed (n ≤ 10).
🛠  Review: correct; O(n) — Already optimal.
*/
