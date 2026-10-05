// Codeforces 1807A — Plus or Minus
// https://codeforces.com/problemset/problem/1807/A
// Topic: math
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1807/A Plus or Minus

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b == c){
            cout << "+\n";
        }else if(a - b == c){
            cout << "-\n";
        }
    }
    return 0;
}

/*
💭 First Idea: Check a+b == c else a-b == c.
🧩 Key Property / Invariant: Exactly one of the two holds (guaranteed).
✅ Key insight: Because one is guaranteed, the else branch can be a plain else.
🔁 Recognition cue for next time: 'Which operation was used' -> test one, else the other.
⏱  Speed fix for next time: cout << (a+b==c ? '+' : '-') << '\n'.
🛠  Review: correct; Already optimal.
*/
