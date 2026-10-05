// Codeforces 758A — Holiday Of Equality
// https://codeforces.com/problemset/problem/758/A
// Topic: math | Tags: arrays
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long max_a = 0, sum = 0;

    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;

        if(x > max_a) max_a = x;
        sum += x;
    }

    cout << (max_a * n - sum) << endl;



    return 0;
}

/*
💭 First Idea: Raise everyone to the maximum: answer = max·n − sum.
🧩 Key Property / Invariant: You can only add, so the target must be the max.
✅ Key insight: Σ(max − a_i) = max·n − Σa_i.
🔁 Recognition cue for next time: "Only increase to make all equal" → target is the max.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/
