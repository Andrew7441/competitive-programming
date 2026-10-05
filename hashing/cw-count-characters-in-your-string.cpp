// Codewars — Count characters in your string
// Topic: hashing | Tags: strings, frequency
// Complexity (yours): O(n log σ) time, O(σ) space (both attempts)
// Merged: Attempt 1 from Codewars/Functions July 2024.md; Attempt 2 from Codewars/2025/February.md

/*

The main idea is to count all the occurring characters in a string. If you have a string like `aba`, then the result should be `{'a': 2, 'b': 1}`.

What if the string is empty? Then the result should be empty object literal, `{}`.

*/

#include <map>
#include <string>

// ---------- Attempt 1 (Functions July 2024) ----------
std::map<char, unsigned> count(const std::string& string) {
    std::map<char, unsigned> chars;

    for (char c : string) {
        chars[c]++;
    }

    return chars;
}

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::map<char, unsigned> count(const std::string& string) {
  std::map<char, unsigned> m;
  
  for(auto i: string){
    m[i]++;
  }
  
  return m;
}
}  // namespace attempt2

/*
💭 First Idea: map[c]++ for every character (same both times).
🧩 Key Property / Invariant: operator[] value-initialises a missing key to 0, then increments.
✅ Key insight: A frequency map in one pass is the whole problem.
🔁 Recognition cue for next time: "count occurrences of each item" -> map / unordered_map / int[256].
⏱  Speed fix for next time: For pure ASCII an int[256] is fastest, but the kata wants a std::map.
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(n log σ) — Already optimal.
*/
