// Codeforces 2167A — Square?
// https://codeforces.com/problemset/problem/2167/A
// Topic: implementation | Tags: math
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a == b && a == c && a == d &&
       b == a && b == c && b == d && 
       c == a && c == b && c == d && 
       d == a && d == b && d == c){
        cout << "YES\n";
       }else{
        cout << "NO\n";
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
💭 First Idea: Check that all four sticks are equal (with many redundant comparisons).
🧩 Key Property / Invariant: A square needs four equal sides.
✅ Key insight: a == b && b == c && c == d is enough (equality is transitive).
🔁 Recognition cue for next time: "Can sticks form a square" -> all equal.
⏱  Speed fix for next time: Write the three-comparison chain; skip symmetric duplicates.
🛠  Review: correct; O(1) -> Already optimal.
*/
