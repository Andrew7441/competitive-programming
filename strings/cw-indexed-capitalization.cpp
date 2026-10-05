// Codewars — Indexed capitalization
// Topic: strings | Tags: implementation
// Complexity (yours): O(n + k) time, O(1) extra space
// From: Codewars/Functions 2.md — section "Function to capitalize all letters at the given indices."
/*
Kata description:
Given a string and an array of integers representing indices, capitalize all letters at the given indices. Indices out of range are ignored.
For example:
- capitalize("abcdef",[1,2,5]) = "aBCdeF"
- capitalize("abcdef",[1,2,5,100]) = "aBCdeF" // there is no index 100.
*/

#include <string>  // [added: include missing in the note; needed to compile]
#include <vector>  // [added: include missing in the note; needed to compile]
std::string capitalize(std::string s, std::vector<int> idxs)
{
  for(int i : idxs)
  {
    if(i < s.size() )
      s[i] = toupper(s[i]);
  }
  return s;
}

/*
💭 First Idea: For each index i < s.size(), uppercase s[i].
🧩 Key Property / Invariant: Out-of-range indices are skipped by the bounds check.
✅ Key insight: Direct indexing; only check bounds.
🔁 Recognition cue for next time: "modify chars at given positions" -> bounds check + direct index.
⏱  Speed fix for next time: Cast i to size_t (or check i >= 0) to avoid the signed/unsigned comparison.
🛠  Review: correct; O(n + k) -> Already optimal.
*/
