// Codeforces (acm.sgu.ru) 100 — A+B
// https://codeforces.com/problemsets/acmsguru/problem/99999/100
// Topic: math | Tags: implementation
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemsets/acmsguru/problem/99999/100 A+B

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A,B;
    cin >> A >> B;
    cout << A + B;

    return 0;
}

/*
💭 First Idea: Read A and B, print A + B.
🧩 Key Property / Invariant: 1 <= A, B <= 10000 so int is enough.
✅ Key insight: Nothing beyond reading input correctly.
🔁 Recognition cue for next time: Warm-up problem - check the constraints for overflow.
⏱  Speed fix for next time: Use long long by default when constraints are unclear.
🛠  Review: correct; Already optimal.
*/
