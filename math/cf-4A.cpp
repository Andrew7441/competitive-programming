// Codeforces 4A — Watermelon
// https://codeforces.com/problemset/problem/4/A
// Topic: math | Tags: parity
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a;
  cin >> a;
  if (a % 2 == 0 && a > 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

/*
💭 First Idea: Check w is even and w > 2.
🧩 Key Property / Invariant: Two even parts sum to an even number; each part must be >= 2.
✅ Key insight: w=2 is the only even number that fails (1+1 are odd).
🔁 Recognition cue for next time: 'Split into two even parts' -> parity check plus the smallest edge case.
⏱  Speed fix for next time: Test the smallest inputs (1, 2, 3) before submitting.
🛠  Review: correct; Already optimal.
*/
