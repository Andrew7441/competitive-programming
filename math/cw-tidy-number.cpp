// Codewars — Tidy Number (Special Numbers Series #9)
// Topic: math | Tags: digits, strings
// Complexity (yours): O(d) time, O(d) space (d = number of digits)
// ⚠️ Review: loop starts at i = 0 and reads res[-1] (out of bounds, UB); see corrected version below.
// From: Codewars/Functions.md — section "Function returns true if numbers are in non-decreasing order"
// Import note: closing brace of tidyNumber was missing in the note; added so it compiles.
/*
Kata description:
A Tidy number is a number whose digits are in non-decreasing order. Given a positive number, return true if it is Tidy, false otherwise.
Examples: 12 -> true, 32 -> false, 1024 -> false, 13579 -> true, 2335 -> true.
*/

#include <string>

using namespace std; 


bool tidyNumber (int number)
{
  string res = std::to_string(number);
  for(int i = 0;i<res.size();i++){
    if(res[i]<res[i-1]){
      return false;
    }
  }
  return true;
//basically it checks the number and the number before it.
//ex: 12 -> checks 1<0 -> returns true
//       -> checks 2<1 -> returns true
//ex: 93 -> checks 9<0 -> returns true
//       -> checks 3<9 -> returns false
}  // [added: closing brace missing in the note]

// ===================== ⚡ Optimized =====================
// Fix: compare each digit with the previous one starting at i = 1 (there is nothing before index 0).
namespace optimized {
bool tidyNumber(int number) {
  std::string s = std::to_string(number);
  for (size_t i = 1; i < s.size(); i++)
    if (s[i] < s[i - 1]) return false;
  return true;   // equivalently: return std::is_sorted(s.begin(), s.end());
}
}

/*
💭 First Idea: Convert to string and check each digit is >= the previous one.
🧩 Key Property / Invariant: Non-decreasing digits <=> no adjacent pair with s[i] < s[i-1].
✅ Key insight: Start comparing at i = 1; or just std::is_sorted on the digit string.
🔁 Recognition cue for next time: "digits in order" -> to_string + is_sorted.
⏱  Speed fix for next time: Never index i-1 when i can be 0; start the loop at 1.
🛠  Review: wrong because res[-1] is UB (owner thought it reads 0); O(d) -> fixed O(d).
*/
