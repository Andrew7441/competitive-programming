// Codeforces 1950A — Stair, Peak, or Neither?
// https://codeforces.com/problemset/problem/1950/A
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
        int a, b, c;
        cin >> a >> b >> c;

        if(a < b && b < c){
            cout << "STAIR\n";
        }else if(a < b && b > c){
            cout << "PEAK\n";
        }else{
            cout << "NONE\n";
        }
    }
    return 0;
}

/*
💭 First Idea: Direct comparisons of a, b, c.
🧩 Key Property / Invariant: STAIR = strictly increasing, PEAK = up then down, else NONE.
✅ Key insight: Just translate the definitions into if/else.
🔁 Recognition cue for next time: Three numbers + named shape -> plain case work.
⏱  Speed fix for next time: Write the conditions exactly as stated, strict inequalities.
🛠  Review: correct; Already optimal.
*/
