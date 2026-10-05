// Codewars — Reverse words
// Topic: strings | Tags: two-pointers
// Complexity (yours): O(n) time, O(1) extra space
// From: Codewars/Functions.md — section "(untitled block after "Function to return a specific word")"
/*
Kata description:
Reverse each word in the string while keeping word order and ALL spaces (including multiple spaces).
Example: "This is an example!" -> "sihT si na !elpmaxe".
*/

#include <algorithm>
#include <string>

std::string reverse_words(std::string str) {
  auto i = str.begin();
  auto j = str.end();
  while (i < j) {
    auto k = std::find(i, j, ' ');
    std::reverse(i, k);
    i = k+1;
  }
  return str;
}

// ===================== ⚡ Optimized =====================
// Same idea, but never moves the iterator past end(): i = k + 1 when k == end() is undefined behaviour.
namespace optimized {
std::string reverse_words(std::string str) {
  auto i = str.begin();
  while (true) {
    auto k = std::find(i, str.end(), ' ');
    std::reverse(i, k);
    if (k == str.end()) break;
    i = k + 1;
  }
  return str;
}
}

/*
💭 First Idea: Find each space with std::find and std::reverse the range between spaces, in place.
🧩 Key Property / Invariant: Every space stays at its index; only characters between spaces move.
✅ Key insight: Reversing each [wordStart, nextSpace) range in place keeps multiple spaces intact.
🔁 Recognition cue for next time: "reverse each word but keep spacing" -> in-place reverse between separators (do not split with >>, it eats spaces).
⏱  Speed fix for next time: Break out when find returns end() instead of stepping past it.
🛠  Review: correct in practice but i = end()+1 is UB on the last word; O(n) -> UB-free O(n) version.
*/
