// Codeforces 1993A — Question Marks
// https://codeforces.com/problemset/problem/1993/A
// Topic: greedy | Tags: strings, counting
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int a = 0, b = 0, c = 0, d = 0;

    for(char &i: s){
        if(i == 'A') a++;
        else if(i == 'B') b++;
        else if(i == 'C') c++;
        else if(i == 'D') d++;
    }

    cout << min(n, a) + min(n,b) + min(n, c) + min(n, d) << "\n";
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
💭 First Idea: Count each of A/B/C/D; answer = sum of min(n, count).
🧩 Key Property / Invariant: Exactly n correct answers per letter, so a letter can contribute at most n points.
✅ Key insight: Each letter contributes min(n, cnt[letter]); '?' never scores.
🔁 Recognition cue for next time: "Each option is correct exactly k times" -> cap each frequency at k.
⏱  Speed fix for next time: Use int cnt[256] and loop over "ABCD".
🛠  Review: correct; Already optimal.
*/
