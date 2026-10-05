// Codeforces 2227A — Koshary
// https://codeforces.com/problemset/problem/2227/A
// Topic: math | Tags: implementation
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int x, y;
    cin >> x >> y;

    if(x % 2 != 0 && y % 2 != 0){
        cout << "NO\n";
    }else if(x % 2 == 0 && y % 2 != 0){
        cout << "YES\n";
    }else if(x % 2 != 0 && y % 2 == 0){
        cout << "YES\n";
    }else if(x % 2 == 0 && y % 2 == 0){
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}

/*
💭 First Idea: Case analysis on the parities of x and y.
🧩 Key Property / Invariant: Long steps keep both coordinates' parity; the single short step can fix the parity of only one coordinate.
✅ Key insight: Reachable iff x and y are not both odd.
🔁 Recognition cue for next time: "Steps of size 2 plus at most one step of size 1" -> parity check.
⏱  Speed fix for next time: One line: cout << (x % 2 && y % 2 ? "NO" : "YES").
🛠  Review: correct; O(1) -> Already optimal (the 4-branch if can be one condition).
*/