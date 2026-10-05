// Codewars — Count by X
// Topic: math | Tags: arrays, multiples
// Complexity (yours): O(n) time, O(n) space (both attempts)
// Merged: Attempt 1 from Codewars/September 2024.md; Attempt 2 from Codewars/2025/July/Practice.md

/*
Create a function with two arguments that will return an array of the first `n` multiples of `x`.

Assume both the given number and the number of times to count will be positive numbers greater than `0`.

Return the results as an array or list ( depending on language ).

### Examples

x = 1, n = 10 --> [1,2,3,4,5,6,7,8,9,10]
x = 2, n = 5  --> [2,4,6,8,10]

*/

#include <vector>

// ---------- Attempt 1 (September 2024) ----------
std::vector<int> countBy(int x,int n){
  std::vector<int> c;
  for(int i=x;i<=n*x;i+=x){
    c.push_back(i);
  }
  return c;
}

// ---------- Attempt 2 (July 2025 Practice) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::vector<int> countBy(int x,int n){
  std::vector<int> res;
  for(int i = x ; i <= n*x ; i+=x){
    res.push_back(i);
  }
  return res;
}
}  // namespace attempt2

/*
💭 First Idea: Step i from x to n*x in increments of x (same both times).
🧩 Key Property / Invariant: The k-th multiple is k*x for k = 1..n.
✅ Key insight: Loop over the count k (1..n) and push k*x — avoids depending on the n*x bound.
🔁 Recognition cue for next time: "first n multiples" -> for k in 1..n: k*x.
⏱  Speed fix for next time: res.reserve(n); for (int k = 1; k <= n; ++k) res.push_back(k * x);
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(n) — Already optimal.
*/
