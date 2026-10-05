// Codeforces 1894A — Secret Sport
// https://codeforces.com/problemset/problem/1894/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(1) extra time (O(n) read), O(n) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << s.back() << "\n";
    }

    return 0;
}

/*
💭 First Idea: Print the last character of s.
🧩 Key Property / Invariant: Whoever won the last play also won the last set and therefore the game.
✅ Key insight: The final play always decides the match.
🔁 Recognition cue for next time: 'Who won the whole thing given the play log' -> look at the final event.
⏱  Speed fix for next time: Correct as is.
🛠  Review: correct; Already optimal.
*/
