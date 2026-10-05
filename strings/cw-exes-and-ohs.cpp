// Codewars — Exes and Ohs
// Topic: strings | Tags: counting
// Complexity (yours): O(n) time, O(1) space
// NOTE (reorg): added <string> — missing in the original and needed to compile outside Codewars.
#include <string>

/* APril 28, 2025
Check to see if a string has the same amount of 'x's and 'o's. The method must return a boolean and be case insensitive. The string can contain any char.

Examples input/output:
XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false

*/


#include <cctype>
bool XO(const std::string& str)
{
  int numx = 0;
  int numo = 0;
 
  
  for(char i: str){
    char lower = std::tolower(i);
    if(lower == 'x'){
      numx++;
    }else if(lower == 'o'){
      numo++;
    }
  }
  return numx == numo;
}


/*
💭 First Idea: Lowercase each char, count x's and o's, compare.
🧩 Key Property / Invariant: Case-insensitive: compare tolower(c).
✅ Key insight: Two counters (or one +1/−1 balance) in a single pass.
🔁 Recognition cue for next time: "same number of A and B" -> balance counter.
⏱  Speed fix for next time: One balance int: bal += (c=='x') - (c=='o'); return bal == 0;
🛠  Review: correct; O(n) — Already optimal.
*/
