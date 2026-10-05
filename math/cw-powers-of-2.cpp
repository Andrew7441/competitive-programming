// Codewars — Powers of 2
// Topic: math | Tags: bit-manipulation
// Complexity (yours): O(n) time, O(n) space
// From: Codewars/Functions July 2024.md — section "function that takes a non-negative integer n as input, and returns a list of all the powers of 2 with the exponent ranging from 0 to n"
/*
Kata description:
Complete the function that takes a non-negative integer n as input, and returns a list of all the powers of 2 with the exponent ranging from 0 to n (inclusive).
Examples: n = 0 -> [1]; n = 1 -> [1, 2]; n = 2 -> [1, 2, 4].
*/

#include <vector>
#include <cstdint>
#include<cmath>

std::vector<uint64_t> powers_of_two(int n) {
  std::vector<uint64_t> result;
  
  for(int i=0;i<=n;i++){
    result.push_back(std::pow(2,i));
  }
  return result;
}

// ===================== ⚡ Optimized =====================
// Integer-only: 1ULL << i is exact, while std::pow goes through double (exact here only because powers of 2 fit a double).
namespace optimized {
std::vector<uint64_t> powers_of_two(int n) {
  std::vector<uint64_t> result;
  for (int i = 0; i <= n; i++) result.push_back(1ULL << i);
  return result;
}
}

/*
💭 First Idea: push_back(std::pow(2, i)) for i = 0..n.
🧩 Key Property / Invariant: Each power is the previous one doubled.
✅ Key insight: 2^i == 1ULL << i, exact integer arithmetic.
🔁 Recognition cue for next time: "powers of 2" -> bit shift, never pow().
⏱  Speed fix for next time: Avoid std::pow for integers: it returns double and can round for other bases.
🛠  Review: correct; O(n) -> O(n) without floating point.
*/
