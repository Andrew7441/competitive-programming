// Codeforces 1971A — My First Sorting Problem
// https://codeforces.com/problemset/problem/1971/A
// Topic: implementation
// Complexity (yours): O(1) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;

        if(x > y){
            int temp = x;
            x = y;
            y = temp;
        }
        cout << x << " " << y << "\n";
    }

    return 0;
}

/*
💭 First Idea: Swap x and y if x > y, print.
🧩 Key Property / Invariant: Output is just (min, max).
✅ Key insight: cout << min(x,y) << ' ' << max(x,y).
🔁 Recognition cue for next time: Two values to order -> min/max.
⏱  Speed fix for next time: Use std::min/std::max or std::swap instead of a manual temp swap.
🛠  Review: correct; Already optimal.
*/
