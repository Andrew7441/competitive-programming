// Codeforces 1512A — Spy Detected!
// https://codeforces.com/problemset/problem/1512/A
// Topic: implementation | Tags: arrays
// Complexity (yours): O(n) per test
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

        vector<int> a(n);
        for(int& i : a) cin >> i;

        int common, idx;

        if(a[0] == a[1] || a[0] == a[2]) common = a[0];
        else common = a[1];

        for(int i = 0; i < n; i++){
            if(common != a[i]){
                idx = i + 1;
            }
        }

        cout << idx << "\n";
    }
    return 0;
}

/*
💭 First Idea: Find the common value from the first three elements, then output the index that differs.
🧩 Key Property / Invariant: Among any three elements at least two equal the common value.
✅ Key insight: Majority of a[0..2] identifies the common value.
🔁 Recognition cue for next time: "All equal except one" → look at the first 3 elements.
⏱  Speed fix for next time: Initialize idx (= -1) to silence -Wmaybe-uninitialized; break once found.
🛠  Review: correct; O(n) — Already optimal.
*/
