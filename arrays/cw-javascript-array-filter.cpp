// Codewars — JavaScript Array Filter (C++: get_even_numbers)
// Topic: arrays | Tags: filtering
// Complexity (yours): O(n) time, O(n) space (both attempts)
// Merged: Attempt 1 from Codewars/Functions.md (2024); Attempt 2 from Codewars/2025/February.md
// Import note: closing brace of Attempt 1 get_even_numbers was missing in the note; added so it compiles. Kata name inferred from the function name.

/*
Return a vector containing only the even numbers of the input, in their original order.
The solution would work like the following:
get_even_numbers({2,4,5,6}) => {2,4,6}
*/

#include <vector>
#include <iostream>

// ---------- Attempt 1 (Functions, 2024) ----------
std::vector<int> get_even_numbers(const std::vector<int>& arr) {

std::vector<int> result {};

for(auto& n: arr)
if(n % 2 == 0)
result.push_back(n);

return result;
}  // [added: closing brace missing in the note]

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::vector<int> get_even_numbers(const std::vector<int>& arr) {
  std::vector<int> res;
  
  for(int i : arr){
    if(i % 2 == 0){
      res.push_back(i);
    }
  }
  return res;
}
}  // namespace attempt2

/*
💭 First Idea: Loop over arr and push_back every n with n % 2 == 0 (same idea both times).
🧩 Key Property / Invariant: Order is preserved by a left-to-right scan; x % 2 == 0 also works for negative evens in C++.
✅ Key insight: It is a filter: a single pass is optimal; std::copy_if is the idiom.
🔁 Recognition cue for next time: "keep elements satisfying a predicate" -> loop + push_back or std::copy_if.
⏱  Speed fix for next time: std::copy_if(arr.begin(), arr.end(), std::back_inserter(res), [](int x){ return x % 2 == 0; });
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(n) — Already optimal.
*/
