// Codewars — Remove anchor from URL
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(n) space
// From: Codewars/Functions.md — section "function/method so that it returns the url with anything after the anchor (#) removed."
// Import note: second ("better") version wrapped in namespace attempt2 so both definitions compile; added <string> include.
/*
Kata description:
Complete the function so that it returns the URL with anything after the anchor (#) removed.
Example: "www.codewars.com#about" -> "www.codewars.com"; "www.codewars.com?page=1" -> unchanged.
*/

#include <string>  // [added: include missing in the note; needed to compile]
#include<algorithm>
std::string replaceAll(std::string str) {
  size_t pos = str.find("#");
  if(pos != std::string::npos)
    str.erase(pos);
    
  return str;  
}

//better code would be
// Attempt 2
namespace attempt2 {  // [added wrapper so both versions compile]
std::string replaceAll(std::string str) {
  return str.substr(0, str.find('#'));
}
}  // namespace attempt2

/*
💭 First Idea: find("#") and erase from there if found.
🧩 Key Property / Invariant: find returns npos when absent, and substr(0, npos) returns the whole string.
✅ Key insight: substr(0, find('#')) handles both cases with no branch.
🔁 Recognition cue for next time: "cut everything after a delimiter" -> substr(0, find(delim)).
⏱  Speed fix for next time: Remember npos as length means "until the end".
🛠  Review: correct; O(n) -> Already optimal.
*/
