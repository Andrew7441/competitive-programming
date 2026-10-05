// Codeforces 2182A — New Year String
// https://codeforces.com/problemset/problem/2182/A
// Topic: strings | Tags: greedy
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;

    if(s.find("2025") != string::npos ){
        if(s.find("2026") == string::npos){
            for(int i = 0; i < (int)s.size(); i++){
               if(s[i] == '5'){
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << "\n";
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
💭 First Idea: If '2025' appears and '2026' does not, answer 1, else 0.
🧩 Key Property / Invariant: Changing the 5 of any '2025' into 6 creates '2026', which fixes the string in one move.
✅ Key insight: The answer is only 0 or 1; the loop looking for '5' is redundant (it is inside '2025').
🔁 Recognition cue for next time: "Contains A or doesn't contain B" with one edit -> turn a B into an A.
⏱  Speed fix for next time: Print (has2025 && !has2026) directly.
🛠  Review: correct; O(n) -> Already optimal.
*/
