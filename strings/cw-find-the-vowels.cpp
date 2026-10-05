// Codewars — Find the vowels
// Topic: strings | Tags: indexing, hashing
// Complexity (yours): O(n) time, O(n) space (both attempts)
// Merged: Attempt 1 from Codewars/Functions July 2024.md; Attempt 2 from Codewars/2025/February.md
// Import note: closing brace of Attempt 1 vowelIndices was missing in the note; added. The "Find the vowels" title line was bare text in the 2025 note; prefixed with "// ".

// Find the vowels
/*
We want to know the index of the vowels in a given word, for example, there are two vowels in the word super (the second and fourth letters).
Some examples:
Mmmm  => []
Super => [2,4]
Apple => [1,5]
YoMama -> [1,2,4,6]
So given a string "super", we should return a list of `[2, 4]`.
- Vowels in this context refers to: a e i o u y (including upper case)
- This is indexed from `[1..n]` (not zero indexed!)
*/

#include <vector>
#include <string>
#include <set>
#include <cctype>

// ---------- Attempt 1 (Functions July 2024) ----------
std::vector<int> vowelIndices(const std::string& w)
{
  std::set<char> v = { 'a','e','i','o','u','y'};
  std::vector<int> res;
  
  for(int i = 0; i < w.size(); i++)
  {
    if(v.find(std::tolower(w[i])) != v.end())
      res.push_back(i+1);
  }
  return res;
}  // [added: closing brace missing in the note]

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::vector<int> vowelIndices(const std::string& word)
{
  std::set<char> v = { 'a','e','i','o','u','y'};
  std::vector<int> res;
  
  for(int i = 0; i < word.size(); i++){
    if(v.find(std::tolower(word[i])) != v.end()){
      res.push_back(i+1);
    }
  }
    return res;
}
}  // namespace attempt2

/*
💭 First Idea: Set of vowels (incl. y); push i + 1 for every char whose lowercase is in the set (same both times).
🧩 Key Property / Invariant: Positions are 1-based and the check is case-insensitive.
✅ Key insight: Lowercase each char once, then a membership test.
🔁 Recognition cue for next time: "positions of chars from a set" -> single loop pushing 1-based indices.
⏱  Speed fix for next time: A string "aeiouy" with find() (or a bool[26]) is lighter than std::set for 6 chars.
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(n) — Already optimal.
*/
