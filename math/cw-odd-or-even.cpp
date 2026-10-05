// Codewars — Odd or Even?
// Topic: math | Tags: parity, arrays
// Complexity (yours): O(n) time, O(1) space (all attempts)
// Merged: Attempt 1 from Codewars/Functions.md (2024); Attempt 2 from Codewars/2025/February.md; Attempt 3 from Codewars/2025/July/Practice.md

/*
Given a list of integers, determine whether the sum of its elements is odd or even.

Give your answer as a string matching `"odd"` or `"even"`.

If the input array is empty consider it as: `[0]` (array with a zero).

### Examples:


Input: [0]
Output: "even"

Input: [0, 1, 4]
Output: "odd"

Input: [0, -1, -5]
Output: "even"

*/

#include <string>
#include <vector>

// ---------- Attempt 1 (Functions, 2024) ----------
std::string odd_or_even(const std::vector<int> &arr)
{
  int sum = 0;
  
  for(auto i: arr)
    sum +=i;
  
  if(sum % 2 == 0)
    return "even";
  else
    return "odd";
  
}

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::string odd_or_even(const std::vector<int> &arr)
{
  if(arr.empty()){
    return "even";
  }
  
  int sum = 0;
  
  for(int i: arr)
    sum+= i;
  
  return (sum % 2 == 0) ? "even" : "odd";
}
}  // namespace attempt2

// ---------- Attempt 3 (July 2025 Practice) ----------
namespace attempt3 {  // (wrapper added in merge so all attempts compile in one file)
std::string odd_or_even(const std::vector<int> &arr)
{
    if(arr.empty()){
      return "even";
    }
  
  int sum = 0;
  for(auto i: arr){
    sum += i;
  }
  
  return sum % 2 == 0 ? "even" : "odd";
}
}  // namespace attempt3

/*
💭 First Idea: Sum all elements, then check sum % 2 (Attempts 2-3 add an explicit empty check).
🧩 Key Property / Invariant: Parity of a sum = XOR of the parities; sum % 2 == 0 works for negatives too (-3 % 2 == -1 != 0); empty sum = 0 = even.
✅ Key insight: Only the parity matters; the empty check is redundant because an empty loop leaves sum = 0.
🔁 Recognition cue for next time: "odd or even of a total" -> think parity, not the full value.
⏱  Speed fix for next time: Use long long (or accumulate x & 1) so huge inputs cannot overflow; std::accumulate for the sum.
🛠  Review: Attempt 1 correct, Attempt 2 correct, Attempt 3 correct; O(n) — Already optimal.
*/
