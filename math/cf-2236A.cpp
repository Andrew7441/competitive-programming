// Codeforces 2236A — Games on the Train
// https://codeforces.com/problemset/problem/2236/A
// Topic: math | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin >> n;

    int mx = INT_MIN, mn = INT_MAX;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }

    cout << mx - mn + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

/*
💭 First Idea: Answer = max - min + 1.
🧩 Key Property / Invariant: Final height T >= max + 1 because every x_i >= 1; the smallest tower then needs x = T - min.
✅ Key insight: Choose T = max + 1: k = max + 1 - min, which is minimal.
🔁 Recognition cue for next time: "Add 1..k to each element to make all equal, minimize k" -> range of the array.
⏱  Speed fix for next time: Track min and max in one pass.
🛠  Review: correct; O(n) -> Already optimal (matches samples).
*/