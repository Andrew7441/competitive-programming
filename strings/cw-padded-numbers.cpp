// Codewars — Substituting Variables Into Strings: Padded Numbers
// Topic: strings | Tags: formatting
// Complexity (yours): O(1)

/*
Complete the solution so that it returns a formatted string. The return value should equal "Value is VALUE" where value is a 5 digit padded number.

Example:
solution(5); // should return "Value is 00005"
*/


#include <string>

std::string solution(int n) {
  std::string s = "00000";
  s += std::to_string(n);
  
  return "Value is " + s.substr(s.length()-5,5);
  
}


/*
💭 First Idea: Prepend "00000" to to_string(n) and keep the last 5 chars.
🧩 Key Property / Invariant: Last 5 chars of zeros+digits = zero-padded 5-digit number (n ≤ 99999).
✅ Key insight: Pad-then-take-suffix is a neat padding trick.
🔁 Recognition cue for next time: "zero-pad to width w" -> std::string(w - len, '0') + s, or snprintf("%05d").
⏱  Speed fix for next time: char buf[16]; snprintf(buf, sizeof buf, "Value is %05d", n); return buf;
🛠  Review: correct; O(1) — Already optimal.
*/
