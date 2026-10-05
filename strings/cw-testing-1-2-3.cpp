// Codewars — Testing 1-2-3
// Topic: strings | Tags: formatting, implementation
// Complexity (yours): O(total length) time and space (all attempts)
// Merged: Attempt 1 from Codewars/Functions.md (2024); Attempt 2 from Codewars/2025/February.md; Attempt 3 from Codewars/2025/May.md

/*
Your team is writing a fancy new text editor and you've been tasked with implementing the line numbering.

Write a function which takes a list of strings and returns each line prepended by the correct number.

The numbering starts at 1. The format is `n: string`. Notice the colon and space in between.

**Examples: (Input --> Output)**

[] --> []
["a", "b", "c"] --> ["1: a", "2: b", "3: c"]

*/

#include <string>
#include <vector>
#include <map>

// ---------- Attempt 1 (Functions, 2024) ----------
std::vector<std::string> number(const std::vector<std::string> &lines)
{
  std::vector<std::string> numlines;
  int linenum = 1;
  
  for(const auto &i: lines){
    numlines.push_back(std::to_string(linenum) + ": " + i);
    linenum++;
  }
  return numlines;
}

// ---------- Attempt 2 (February 2025) ----------
// feb 4
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::vector<std::string> number(const std::vector<std::string> &lines)
{
  std::vector<std::string> res;
  int num = 1;
  
  for(const auto i: lines){
    res.push_back(std::to_string(num) + ": " + i);
    num++;
  }
  return res;
}
}  // namespace attempt2

// ---------- Attempt 3 (May 2025) ----------
namespace attempt3 {  // (wrapper added in merge so all attempts compile in one file)
std::vector<std::string> number(const std::vector<std::string> &lines)
{
  std::vector<std::string> res;
  int num = 1;
  
  for(auto i : lines){
    res.push_back(std::to_string(num) + ": " + i);
    num++;
  }
  return res;
}
}  // namespace attempt3

/*
💭 First Idea: Loop with a counter starting at 1 and build to_string(n) + ": " + line (same all three times).
🧩 Key Property / Invariant: Line i (0-based) gets number i + 1.
✅ Key insight: Plain formatting; nothing algorithmic to optimize.
🔁 Recognition cue for next time: "number the lines / prefix each item with its index" -> index loop + to_string.
⏱  Speed fix for next time: Use `const auto& i` (Attempt 2 `const auto i` and Attempt 3 `auto i` copy each string) and reserve(lines.size()).
🛠  Review: Attempt 1 correct, Attempt 2 correct, Attempt 3 correct; O(total length) — Already optimal.
*/
