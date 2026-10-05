// Codewars — Replace With Alphabet Position
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(n) space

/*
In this kata you are required to, given a string, replace every letter with its position in the alphabet.

If anything in the text isn't a letter, ignore it and don't return it.

`"a" = 1`, `"b" = 2`, etc.
*/
#include <string>

std::string alphabet_position(const std::string &text){
  std::string res = "";
  
  for(char i: text){
    if(std::isalpha(i)){
      int pos = std::tolower(i) - 'a' + 1;
      res += std::to_string(pos) + " ";
    }
  }
   if (!res.empty()) {
    res.pop_back();
  }
  return res; 
}


/*
💭 First Idea: For each letter append tolower(c) - 'a' + 1 and a space; pop the trailing space.
🧩 Key Property / Invariant: Position = lowercase letter − 'a' + 1; non-letters skipped.
✅ Key insight: Build with separators then trim the last one.
🔁 Recognition cue for next time: "map each char to a number, space-separated" -> append + pop_back (or join).
⏱  Speed fix for next time: Cast to unsigned char for isalpha/tolower on non-ASCII input.
🛠  Review: correct; O(n) — Already optimal.
*/
