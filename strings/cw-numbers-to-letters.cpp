// Codewars — Numbers to Letters
// https://www.codewars.com/kata/numbers-to-letters
// Topic: strings | Tags: lookup-table
// Complexity (yours): O(n) time, O(n) space
// From: Codewars/Functions.md — section "Function to return numbers from string"
/*
Kata description:
Given an array of numbers (in string format), return a string. The numbers correspond to the letters of the alphabet in reverse order: a=26, z=1, etc. Also "27" -> '!', "28" -> '?', "29" -> ' '.
*/

#include <string>
#include <vector>

std::string switcher(const std::vector<std::string>& arr) {
  std::string s = " zyxwvutsrqponmlkjihgfedcba!? ";
  std::string r;
  for (const std::string& n: arr) r += s[stoi(n)];
  return r;
}

/*
💭 First Idea: Lookup string where s[k] is the character for code k, then stoi each element.
🧩 Key Property / Invariant: Index 0 is padding; 1..26 is z..a; 27,28,29 are ! ? and space.
✅ Key insight: A lookup table turns the mapping into one index operation.
🔁 Recognition cue for next time: "number -> character mapping" -> build a lookup string.
⏱  Speed fix for next time: Write the table once and index; avoid if/else chains.
🛠  Review: correct; O(n) -> Already optimal.
*/
