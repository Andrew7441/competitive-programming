// Codewars — Get the Middle Character
// Topic: strings | Tags: indexing
// Complexity (yours): O(1) time (substr of ≤ 2 chars)
// NOTE (reorg): added <string> — missing in the original and needed to compile outside Codewars.
#include <string>

/*
You are going to be given a **non-empty** string. Your job is to return the middle character(s) of the string.

- If the string's length is odd, return the middle character.
- If the string's length is even, return the middle 2 characters.

### Examples:
"test" --> "es"
"testing" --> "t"
"middle" --> "dd"
"A" --> "A"

*/

std::string get_middle(std::string i) 
{
  int length = i.length();
  if(length % 2 == 0)
    return i.substr((length/2) - 1, 2);
  else
    return i.substr(length/2,1);
}


/*
💭 First Idea: Even length -> substr(len/2 − 1, 2), odd -> substr(len/2, 1).
🧩 Key Property / Invariant: Middle index is len/2; even lengths need one char to its left too.
✅ Key insight: One-liner: s.substr((len − 1) / 2, 2 − len % 2).
🔁 Recognition cue for next time: "middle element(s)" -> (n−1)/2 start, length depends on parity.
⏱  Speed fix for next time: Fine as is.
🛠  Review: correct; O(1) — Already optimal.
*/
