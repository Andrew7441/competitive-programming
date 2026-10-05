// Codewars — Help Bob count letters and digits.
// Topic: strings | Tags: counting, cctype
// Complexity (yours): O(n) time, O(1) extra space

/*
Create a method that can determine how many letters (both uppercase and lowercase ASCII letters)
and digits are in a given string.

Example:
"hel2!lo" --> 6
*/

#include <string> // added: std::string (missing in the original note)

int countLettersAndDigits(std::string input)
{
  int count = 0;
  
  for(char i: input){
    if(std::isdigit(i)){
      count++;
    }
    if(std::isalpha(i)){
      count++;
    }
  }
  return count;
}

/*
💭 First Idea: loop and add 1 for each digit and each letter.
🧩 Key Property / Invariant: letters and digits are disjoint, so two ifs never double count.
✅ Key insight: std::isalnum(c) is exactly "letter or digit".
🔁 Recognition cue for next time: "count letters and digits" -> isalnum / count_if.
⏱  Speed fix for next time: pass (unsigned char)c to <cctype> functions — negative chars are UB.
🛠  Review: correct; O(n) → Already optimal.
*/
