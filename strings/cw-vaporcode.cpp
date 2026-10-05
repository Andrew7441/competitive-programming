// Codewars — V A P O R C O D E
// Topic: strings | Tags: formatting, implementation
// Complexity (yours): O(n) time, O(n) space (both attempts)
// Merged: Attempt 1 from Codewars/Functions July 2024.md; Attempt 2 from Codewars/2025/March/March 17-22.md

/*
Write a function that converts any sentence into a V A P O R W A V E sentence. a V A P O R W A V E sentence converts all the letters into uppercase, and adds 2 spaces between each letter (or special character) to create this V A P O R W A V E effect.

**Note that spaces should be ignored in this case.**

## Examples


"Lets go to the movies"       -->  "L  E  T  S  G  O  T  O  T  H  E  M  O  V  I  E  S"
"Why isn't my code working?"  -->  "W  H  Y  I  S  N  '  T  M  Y  C  O  D  E  W  O  R  K  I  N  G  ?"

*/

#include <string>
#include <cctype>

// ---------- Attempt 1 (Functions July 2024) ----------
std::string vaporcode(const std::string& s) {
  std::string res;
  
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == ' '){
          continue;
        }
        res.push_back(std::toupper(s[i]));
        res.push_back(' ');
        res.push_back(' ');
    }
    while(res[res.size()-1] == ' '){
      res.pop_back();
    }
    return res;
}

// ---------- Attempt 2 (March 17-22, 2025) ----------
// March 16 , sunday
// ASC Week 1 Challenge 4 (Medium #1)
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::string vaporcode(const std::string &str) {
  std::string res = "";
  
  for(auto i: str){
    if(i == ' '){
      continue;
    }
      
    res.push_back(std::toupper(i));
    res.push_back(' ');
    res.push_back(' ');
  }
  while(res[res.size() - 1] == ' '){
    res.pop_back();
  }
  
  return res;
}
}  // namespace attempt2

/*
💭 First Idea: Skip spaces, append toupper(c) + two spaces, then pop the trailing spaces (same both times).
🧩 Key Property / Invariant: Every non-space char becomes UPPER followed by "  " except the last.
✅ Key insight: Prepend the separator only when res is non-empty, so no trimming is needed.
🔁 Recognition cue for next time: "join items with a separator" -> add separator only if !res.empty().
⏱  Speed fix for next time: res[res.size() - 1] on an empty res (empty / all-space input) is UB — use while (!res.empty() && res.back() == ' ').
🛠  Review: Attempt 1 correct, Attempt 2 correct (both UB only on empty / all-space input); O(n) — Already optimal.
*/
