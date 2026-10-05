// Codewars — Sum of Cubes
// Topic: math | Tags: formula
// Complexity (yours): O(n) time, O(1) space
// From: Codewars/Functions.md — section "Function takes positive integer n, sums all cubed values 1-n, and returns sum"
// Import note: closing brace of sum_cubes was missing in the note; added so it compiles.
/*
Kata description:
Write a function that takes a positive integer n, sums all the cubed values from 1 to n, and returns that sum.
Example: n = 3 -> 1 + 8 + 27 = 36.
*/

unsigned int sum_cubes(unsigned int n) {
  
  unsigned int sum = 0;
  
  for(unsigned int i = 1; i <= n; i++)
    sum += i * i * i;
  
   return sum;
}  // [added: closing brace missing in the note]

// ===================== ⚡ Optimized =====================
// O(1) instead of O(n): 1^3 + ... + n^3 = (n(n+1)/2)^2 (Nicomachus).
namespace optimized {
unsigned int sum_cubes(unsigned int n) {
  unsigned long long t = 1ULL * n * (n + 1) / 2;
  return (unsigned int)(t * t);
}
}

/*
💭 First Idea: Loop i = 1..n and add i*i*i.
🧩 Key Property / Invariant: Sum of first n cubes equals the square of the n-th triangular number.
✅ Key insight: 1^3+...+n^3 = (n(n+1)/2)^2 gives O(1).
🔁 Recognition cue for next time: "sum of powers 1..n" -> there is almost always a closed formula.
⏱  Speed fix for next time: Remember: sum i = n(n+1)/2, sum i^2 = n(n+1)(2n+1)/6, sum i^3 = (sum i)^2.
🛠  Review: correct; yours O(n) -> optimized O(1).
*/
