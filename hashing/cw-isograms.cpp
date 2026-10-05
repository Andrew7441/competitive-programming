// Codewars — Isograms
// Topic: hashing | Tags: strings, set
// Complexity (yours): O(n) average time, O(1) space (≤ 26 letters)

//feb 2
/*An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.
//**Example: (Input --> Output)**
//"Dermatoglyphics" --> true
//"aba" --> false
//"moOse" --> false (ignore letter case)
*/

#include <string>
#include <bits/stdc++.h>

bool is_isogram(const std::string& str)
{
  std::unordered_set<char> count;
  
  for(char c: str){
    c = tolower(c);
    if(count.find(c) == count.end()){
      count.insert(c);
    }else{
      return false;
    }
  }
  return true;
  
}

/*
💭 First Idea: Insert lowercase letters into an unordered_set, fail on the first repeat.
🧩 Key Property / Invariant: A word is an isogram iff no lowercase letter is seen twice.
✅ Key insight: Normalise case first, then it's a duplicate-detection problem.
🔁 Recognition cue for next time: "any repeated element?" -> set / seen-array.
⏱  Speed fix for next time: bool seen[26]{} is faster and simpler than unordered_set for letters; `count.insert(c).second` replaces find+insert.
🛠  Review: correct; O(n) — Already optimal.
*/
