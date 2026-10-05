// Codewars — Sum of odd numbers
// Topic: math | Tags: formula
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions July 2024.md — section "Function to return sum of odd numbers in a triangle"
// Import note: the triangle picture and examples at the top of the code block were not code; they are now // comments.
/*
Kata description:
Given the triangle of consecutive odd numbers (row 1: 1, row 2: 3 5, row 3: 7 9 11, ...), calculate the sum of the numbers in the n-th row (starting at index 1).
1 --> 1, 2 --> 3 + 5 = 8.
*/

//   			 1
//          3     5
//       7     9    11
//   13    15    17    19
//21    23    25    27    29
//...
//1 -->  1
//2 --> 3 + 5 = 8

long long rowSumOddNumbers(unsigned n){
  return n*n*n;
}
//its basicaly n^3, 1^3=1, 2^3=8, 3^3=27,etc..

// ===================== ⚡ Optimized =====================
// Same O(1) formula, but computed in 64-bit: n*n*n in unsigned int overflows for n > 1625.
namespace optimized {
long long rowSumOddNumbers(unsigned n) {
  return 1LL * n * n * n;
}
}

/*
💭 First Idea: Recognized the row sums 1, 8, 27, ... as n^3.
🧩 Key Property / Invariant: Row n has n odd numbers centred around n^2, so the sum is n * n^2.
✅ Key insight: Sum of row n = n^3.
🔁 Recognition cue for next time: "triangle of consecutive numbers, row sum" -> compute first rows and look for a pattern.
⏱  Speed fix for next time: Promote before multiplying: 1LL * n * n * n.
🛠  Review: correct for the kata's n, but n*n*n is evaluated in unsigned int (overflow for n > 1625); O(1) -> O(1) overflow-safe.
*/
