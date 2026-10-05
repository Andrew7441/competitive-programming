// Codewars — Arithmetic progression
// Topic: strings | Tags: math, formatting
// Complexity (yours): O(n) time, O(n) space (output)

/*
In your class, you have started lessons about arithmetic progression. Since you are also a
programmer, you have decided to write a function that will return the first n elements of the
sequence with the given common difference d and first element a. Note that the difference may be
zero!

The result should be a string of numbers, separated by comma and space.

Example
# first element: 1, difference: 2, how many: 5
arithmetic_sequence_elements(1, 2, 5) == "1, 3, 5, 7, 9"
*/

// Attempt 1 (September 2024)
#include <string>

std::string arithmeticSequenceElements(int a, int d, int n)
{
  std::string res = "";
  for(int i=0;i < n ; i++){
    res += std::to_string(a + i * d); // pemdas 
    if(i < n - 1){
      res += ", ";
    }
  }
  return res;
}

// Attempt 2 (March 6, 2025)
#include <string>

namespace attempt2 {
std::string arithmeticSequenceElements(int a, int d, int n)
{
  std::string res = "";
  
  for(int i = 0; i < n; i++){
    res += std::to_string(a + i * d);
    if(i < n - 1){
      res += ", ";
    }
  }
  return res;
}
} // namespace attempt2

/*
💭 First Idea: generate a + i·d for i = 0..n-1 and join with ", ".
🧩 Key Property / Invariant: separator goes between elements only (i < n - 1).
✅ Key insight: the i-th term is a + i·d directly (no running sum needed).
🔁 Recognition cue for next time: "join with separator" -> add the separator before every element except the first.
⏱  Speed fix for next time: use long long for a + i*d if values can be large.
🛠  Review: correct (both attempts identical); O(n) → Already optimal.
*/
