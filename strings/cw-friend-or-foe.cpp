// Codewars — Friend or Foe?
// Topic: strings | Tags: arrays, filtering
// Complexity (yours): O(n) time, O(n) space

/*
Make a program that filters a list of strings and returns a list with only your friends name in it.

If a name has exactly 4 letters in it, you can be sure that it has to be a friend of yours!
Otherwise, you can be sure he's not...

Input = ["Ryan", "Kieran", "Jason", "Yous"]
Output = ["Ryan", "Yous"]

Input = ["Peter", "Stephen", "Joe"]
Output = []

Input strings will only contain letters.  
Note: keep the original order of the names in the output.
*/

// Attempt 1 (September 2024)
#include <string>
#include <vector>

std::vector<std::string> friendOrFoe(const std::vector<std::string>& input) {
  std::vector<std::string> res;
    for(int i = 0; i < input.size(); i++){
      if(input[i].size() == 4){
        res.push_back(input[i]);
      }
    }
  return res;
}

// Attempt 2 (March 5, 2025)
#include <string>
#include <vector>

namespace attempt2 {
std::vector<std::string> friendOrFoe(const std::vector<std::string>& input) {
  std::vector<std::string> res; 
  
  
  for(auto i: input){
    if(i.length() == 4){
      res.push_back(i);
    }
  }
  
  return res;
}
} // namespace attempt2

/*
💭 First Idea: keep every name whose length is exactly 4, in input order.
🧩 Key Property / Invariant: a stable filter — order of kept elements is preserved.
✅ Key insight: std::copy_if with a length predicate is the one-line version.
🔁 Recognition cue for next time: "keep only items with property X, same order" -> filter / copy_if.
⏱  Speed fix for next time: `for (const auto& name : input)` avoids copying each string (attempt 2 copies with `auto i`).
🛠  Review: correct (both attempts); O(n) → Already optimal.
*/
