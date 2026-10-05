// Codewars — Count letters and digits
// Topic: strings | Tags: counting
// Complexity (yours): O(n) time, O(1) space
// NOTE (reorg): added <string>, <cctype> — missing in the original and needed to compile outside Codewars.
#include <string>
#include <cctype>

/*
 determine how many `letters` (both uppercase and lowercase **ASCII** letters) and `digits` are in a given string.

Example:

"hel2!lo" --> 6

"wicked .. !" --> 6

"!?..A" --> 1
*/

int countLettersAndDigits(std::string input)
{
  int res = 0;
  for(int i = 0; i < input.length(); i++){
    if(std::isalpha(input[i])){
      res++;
    }else if(std::isdigit(input[i])){
      res++;
    }
  }
  
  return res;
}


/*
💭 First Idea: Loop; count chars where isalpha or isdigit.
🧩 Key Property / Invariant: isalpha || isdigit == isalnum.
✅ Key insight: One pass with std::isalnum.
🔁 Recognition cue for next time: "count chars of a class" -> <cctype> + count_if.
⏱  Speed fix for next time: return std::count_if(input.begin(), input.end(), [](unsigned char c){ return std::isalnum(c); }); (cast avoids UB on non-ASCII chars).
🛠  Review: correct; O(n) — Already optimal.
*/
