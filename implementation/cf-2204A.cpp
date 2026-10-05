// Codeforces 2204A — Passing the Ball
// https://codeforces.com/problemset/problem/2204/A
// Topic: implementation | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int res = 1;

    for(int i = 1; i < (int)s.size(); i++){
        if(s[i] == 'R') res++;
        if(s[i] == 'L'){
            res++;
            break;
        }
    }

    cout << res << "\n";
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
💭 First Idea: Walk right from student 1 until the first L; the ball then bounces between that student and the previous one.
🧩 Key Property / Invariant: Student p (first L) passes back to p-1, which is an R and passes forward again -> ping-pong forever.
✅ Key insight: Answer = index (1-based) of the first L in s.
🔁 Recognition cue for next time: "Ball passed by L/R rules" -> find the first place where two neighbours point at each other.
⏱  Speed fix for next time: Print the first L position + 1 (0-based find) directly.
🛠  Review: correct; O(n) -> Already optimal.
*/
