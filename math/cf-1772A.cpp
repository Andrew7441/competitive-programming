// Codeforces 1772A — A+B?
// https://codeforces.com/problemset/problem/1772/A
// Topic: math | Tags: strings, implementation
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1772/A A. A+B

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        cout << a + b << "\n";
    }

    return 0;
}

/*
💭 First Idea: Read a, then read b - the stream parses "+7" as the signed integer 7.
🧩 Key Property / Invariant: Input is a single token "a+b" with one-digit operands.
✅ Key insight: cin >> int stops at '+', and '+d' is a valid signed int.
🔁 Recognition cue for next time: Expression input -> either parse chars (s[0]-'0' + s[2]-'0') or let the stream do it.
⏱  Speed fix for next time: Reading as a string and using s[0], s[2] is clearer and doesn't rely on the '+' trick.
🛠  Review: correct; Already optimal.
*/
