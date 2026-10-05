// Codeforces 2227B — Party Monster
// https://codeforces.com/problemset/problem/2227/B
// Topic: strings | Tags: greedy, counting
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int open = 0;
    int closed = 0;

    for(char c : s){
        if(c == '(') open++;
        else closed++;
    }

    if(open == closed) cout << "YES\n";
    else cout << "NO\n";
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
💭 First Idea: Count "(" and ")"; answer YES iff they are equal.
🧩 Key Property / Invariant: Choosing the whole string as the removed substring lets you reinsert characters in any order.
✅ Key insight: Any arrangement is reachable, so a regular sequence exists iff #"(" == #")".
🔁 Recognition cue for next time: "Remove a substring and reinsert its characters anywhere" -> take the whole string, only counts matter.
⏱  Speed fix for next time: Try the extreme choice of the operation (whole string) first.
🛠  Review: correct; O(n) -> Already optimal.
*/