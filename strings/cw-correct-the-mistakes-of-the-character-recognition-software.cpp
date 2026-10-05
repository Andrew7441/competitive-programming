// Codewars — Correct the mistakes of the character recognition software
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(1) extra space
// From: Codewars/Functions July 2024.md — section "Correct the mistakes of the character recognition software"
// Import note: the owner's "Better solution" is wrapped in namespace attempt2 so both definitions compile; <algorithm> added for std::replace.
/*
Kata description:
Character recognition software is widely used to digitise printed texts. When documents (especially old typewritten ones) are digitised, the software often makes mistakes.
Your task is to correct the errors in the digitised text. You only have to handle the following mistakes:
- S is misinterpreted as 5
- O is misinterpreted as 0
- I is misinterpreted as 1
The test cases contain numbers only by mistake.
*/

#include <string>

std::string correct(std::string str){
  int length = str.length();
  
  for(int i=0;i<length;i++){
    if(str[i] == '1'){
      str[i] = 'I';
    }
    if(str[i] == '0'){
      str[i] = 'O';
    }
    if(str[i] == '5'){
      str[i] = 'S';
    }
  }
  return str;
}

// Attempt 2 (owner: "Better solution")
#include <algorithm>  // [added: include missing in the note; needed to compile]
#include <string>

namespace attempt2 {  // [added wrapper so both versions compile]
std::string correct(std::string str){
  replace(str.begin(), str.end(), '5', 'S');
  replace(str.begin(), str.end(), '0', 'O');
  replace(str.begin(), str.end(), '1', 'I');
  return str;
}
}  // namespace attempt2

/*
💭 First Idea: Loop and replace '1'->'I', '0'->'O', '5'->'S' in place.
🧩 Key Property / Invariant: Each wrong digit maps to exactly one letter.
✅ Key insight: std::replace(begin, end, from, to) per mapping, or one pass with a switch.
🔁 Recognition cue for next time: "fix a few character substitutions" -> std::replace or a per-char switch.
⏱  Speed fix for next time: Use else-if in the loop (or a switch) so each char is tested once.
🛠  Review: correct; O(n) -> Already optimal.
*/
