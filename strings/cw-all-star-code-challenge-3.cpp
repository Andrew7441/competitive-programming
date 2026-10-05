// Codewars — All Star Code Challenge #3
// Topic: strings | Tags: regex, erase-remove
// Complexity (yours): attempt 1 O(n^2) (replace shifts the tail each time), attempt 2 O(n) regex; O(n) space

/*
Create a function that takes a string argument and returns that same string with all vowels
removed (vowels are "a", "e", "i", "o", "u").

"drake" --> "drk"
"aeiou" --> ""
*/

// Attempt 1
#include <string>
#include <algorithm> // added: std::find (missing in the original note)

std::string remove_vowels(std::string str) {
  std::vector<char> v = {'a', 'e', 'i', 'o', 'u', 
                         'A', 'E', 'I', 'O', 'U'};
  
  for(int i = 0; i< str.length();i++){
    if(std::find(v.begin(),v.end(),str[i])!= v.end()){
      str = str.replace(i,1, "");
      i-=1;
    }
  }
  return str;
  
}
// OR, done this on my own
// Attempt 2
#include <string>
#include <regex>

namespace attempt2 {

std::string remove_vowels(const std::string& str) {
  std::regex vowel_regex("a|e|i|o|u");
  std::string replaced_text = std::regex_replace(str, vowel_regex, "");

  return replaced_text;
}

} // namespace attempt2

// ===================== ⚡ Optimized =====================
// O(n) without regex overhead: erase–remove idiom, one pass.
namespace optimized {
std::string remove_vowels(std::string str) {
  str.erase(std::remove_if(str.begin(), str.end(), [](char c) {
              return std::string("aeiou").find(c) != std::string::npos;
            }), str.end());
  return str;
}
}

/*
💭 First Idea: attempt 1 erases each vowel in place and steps back; attempt 2 regex_replace("a|e|i|o|u").
🧩 Key Property / Invariant: after erasing at i, the next char moves into position i (hence i -= 1).
✅ Key insight: "remove all chars matching X" = erase(remove_if(...), end) — linear, no index juggling.
🔁 Recognition cue for next time: deleting many elements from a string/vector -> erase–remove idiom.
⏱  Speed fix for next time: regex "[aeiou]" is the cleaner pattern; std::regex is slow to construct, avoid in hot loops.
🛠  Review: correct (kata uses lowercase vowels); attempt 1 O(n^2) → optimized O(n).
*/
