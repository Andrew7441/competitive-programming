// Codewars — Fix string case
// Topic: strings | Tags: counting
// Complexity (yours): O(n) time, O(1) extra space (both attempts)
// Merged: Attempt 1 from Codewars/Functions.md (2024); Attempt 2 from Codewars/2025/February.md

/*
given a string that may have mixed uppercase and lowercase letters and your task is to convert that string to either lowercase only or uppercase only based on:

- make as few changes as possible.
- if the string contains equal number of uppercase and lowercase letters, convert the string to lowercase.
solve("coDe") = "code". Lowercase characters > uppercase. Change only the "D" to lowercase.
solve("CODe") = "CODE". Uppercase characters > lowecase. Change only the "e" to uppercase.
solve("coDE") = "code". Upper == lowercase. Change all to lowercase.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// ---------- Attempt 1 (Functions, 2024) ----------
std::string solve(std::string str) {
std::size_t upperCaseCount = 0; // size_t is unsigned int type,var to count upper case lettters
for (char c : str) { // loop to check if there are upper case letters, if so, increment
if (std::isupper(c)) {
upperCaseCount++;
}
}
if (upperCaseCount > str.length() / 2) { // checks if uppercase is more than half length of the string 
std::transform(str.begin(), str.end(), str.begin(), ::toupper); // if it is , convert entire string to uppercase using transform
} else {
std::transform(str.begin(), str.end(), str.begin(), ::tolower); //else if not
}
return str;
}

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::string solve(std::string str){
   std::size_t upper = 0;
  
  for(char c : str){
    if(std::isupper(c)){
      upper++;
    }
  }
  if(upper > str.length()/2){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  }else{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}
  return str;
}
}  // namespace attempt2

/*
💭 First Idea: Count uppercase letters; if strictly more than half the length, uppercase all, else lowercase all (same both times).
🧩 Key Property / Invariant: Strings are letters only, so upper > len/2 (integer division) <=> upper > lower; a tie goes to lowercase.
✅ Key insight: Count once, then one std::transform; `>` handles the tie rule automatically.
🔁 Recognition cue for next time: "fewest changes to make it uniform" -> majority vote, then transform.
⏱  Speed fix for next time: std::count_if for the count; cast to unsigned char before isupper/toupper to avoid UB on non-ASCII.
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(n) — Already optimal.
*/
