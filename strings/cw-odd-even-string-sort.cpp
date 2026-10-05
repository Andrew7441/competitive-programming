// Codewars — Odd-Even String Sort
// Topic: strings | Tags: indexing
// Complexity (yours): O(n) time, O(n) space

/*
Given a string s, your task is to return another string such that even-indexed and odd-indexed
characters of s are grouped and the groups are space-separated. Even-indexed group comes as
first, followed by a space, and then by the odd-indexed part.

Examples
input:    "CodeWars" => "CdWr oeas"
           ||||||||      |||| ||||
indices:   01234567      0246 1357

Even indices 0, 2, 4, 6, so we have "CdWr" as the first group.
Odd indices are 1, 3, 5, 7, so the second group is "oeas".
And the final string to return is "Cdwr oeas".
*/

#include <string>

std::string sortMyString(const std::string &s)
{
  std::string even;
  std::string odd;
  
  for(int i =0; i<s.length(); i++){
    if(i%2==0){
      even.push_back(s[i]);
    }else{
      odd.push_back(s[i]);
    }
  }
  return even + " " + odd;
}

/*
💭 First Idea: one pass, push even-index chars to one string and odd-index chars to another, join with a space.
🧩 Key Property / Invariant: relative order inside each group is the original order.
✅ Key insight: splitting by index parity = two output buffers in a single loop.
🔁 Recognition cue for next time: "group by index parity" -> i % 2 (or two loops with step 2).
⏱  Speed fix for next time: two loops `for (i = 0; i < n; i += 2)` / `for (i = 1; ...)` avoid the branch.
🛠  Review: correct; O(n) → Already optimal.
*/
