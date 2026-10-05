// Codewars — Remove exclamation marks
// Topic: strings | Tags: erase-remove
// Complexity (yours): O(n) time, O(n) space
// From: Codewars/Functions July 2024.md — section "Remove exclamation marks"
// Import note: the second version is wrapped in namespace attempt2 so both definitions compile; <algorithm> added for std::remove.
/*
Kata description:
Write function RemoveExclamationMarks which removes all exclamation marks from a given string.
Example: "Hello World!" -> "Hello World".
*/

#include <algorithm>  // [added: include missing in the note; needed to compile]
#include <string>

std::string removeExclamationMarks(std::string str){
  std::string n = "";
  
  for(char c: str)
    if(c!='!')
      n += c;
  
  return n;
}//better code that i wrote but deleted it due to simple mistake:
#include <string>

// Attempt 2
namespace attempt2 {  // [added wrapper so both versions compile]
std::string removeExclamationMarks(std::string str){
  str.erase(std::remove(str.begin(), str.end(), '!'), str.end());
  return str;
}
}  // namespace attempt2

/*
💭 First Idea: Copy every char that is not '!' into a new string.
🧩 Key Property / Invariant: Order of the remaining characters is preserved.
✅ Key insight: Erase-remove idiom: str.erase(std::remove(b, e, '!'), e).
🔁 Recognition cue for next time: "delete all occurrences of a char" -> erase-remove (or std::erase in C++20).
⏱  Speed fix for next time: Remember std::remove needs <algorithm> and must be followed by erase.
🛠  Review: correct; O(n) -> Already optimal.
*/
