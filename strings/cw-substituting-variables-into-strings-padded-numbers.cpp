// Codewars — Substituting Variables Into Strings: Padded Numbers
// Topic: strings | Tags: formatting
// Complexity (yours): O(1) time, O(1) space

/*
Complete the solution so that it returns a formatted string. The return value should
equal "Value is VALUE" where value is a 5 digit padded number.
*/

#include <string>

std::string solution(int n){
  std::string s = "00000";
  s += std::to_string(n);
  
  return "Value is " + s.substr(s.length() - 5, 5);
}

/*
💭 First Idea: prepend "00000" to the number and keep the last 5 characters.
🧩 Key Property / Invariant: n is in [0, 99999], so the last 5 chars of "00000"+n are exactly the padded value.
✅ Key insight: left-padding = "pad with enough zeros, then take the suffix".
🔁 Recognition cue for next time: "N-digit padded number" -> zero-fill formatting.
⏱  Speed fix for next time: one-liner with std::ostringstream << std::setw(5) << std::setfill('0') << n, or snprintf("%05d").
🛠  Review: correct; O(1) → Already optimal.
*/
