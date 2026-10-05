// Codeforces 546A — Soldier and Bananas
// https://codeforces.com/problemset/problem/546/A
// Topic: math | Tags: implementation
// Complexity (yours): O(w) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, w;
    cin >> k >> n >> w;

    int total = 0;

    for(int i = 1; i <= w; i++){
        total += i * k;
    }

    int need = total - n;

    if(total < n){
        cout << 0;
    }else{
        cout << need << '\n';
    }

    return 0;
}

/*
💭 First Idea: Sum k·i for i=1..w in a loop, then answer max(0, total − n).
🧩 Key Property / Invariant: Cost of i-th banana is i·k, so total = k·w(w+1)/2 (≤ 5·10^8, fits int).
✅ Key insight: Closed-form arithmetic series gives O(1); loop is fine for w ≤ 1000.
🔁 Recognition cue for next time: "i-th item costs i·k" → arithmetic series formula.
⏱  Speed fix for next time: cout << max(0, k*w*(w+1)/2 - n);
🛠  Review: correct; O(w) — Already optimal for constraints (O(1) formula possible).
*/
