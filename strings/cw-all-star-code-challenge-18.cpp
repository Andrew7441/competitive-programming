// Codewars — All Star Code Challenge #18
// Topic: strings | Tags: counting
// Complexity (yours): O(n) time, O(1) space
// From: Codewars/Functions.md — section "(untitled strCount block after "Function to convert string to lower or uppercase")"
// Import note: the "-----" separator line was not valid C++ and is now a // comment; the community solution is wrapped in namespace community so both definitions compile.
/*
Kata description:
Create a function that accepts a string and a single character, and returns the number of times the character occurs in the string. If there are no occurrences, return 0.
Example: strCount("Hello", 'o') -> 1.
*/

#include <string>

unsigned int strCount(const std::string& word, char letter){
  
  unsigned int occ = 0;
  
  for(std::size_t i=0; i<word.size();i++)
    
    if(letter == word[i])
      occ++;
    
     return occ;
}
//Create a function that accepts a string and a single character, and returns an integer of the count of occurrences the 2nd argument is found in the first one.
//If no occurrences can be found, a count of 0 should be returned
// ----------------------------------------
// code taken by codewars player
#include <algorithm>
#include <string>

namespace community {  // [added wrapper so both versions compile]
unsigned strCount(const std::string& word, char letter) {
  return std::count(word.cbegin(), word.cend(), letter);
}

//used count function
}  // namespace community

/*
💭 First Idea: Loop over the string and count positions equal to letter.
🧩 Key Property / Invariant: Simple frequency count of one character.
✅ Key insight: std::count(begin, end, ch) does it in one line.
🔁 Recognition cue for next time: "count occurrences of a value" -> std::count / std::count_if.
⏱  Speed fix for next time: Reach for <algorithm> first: count, find, replace, remove.
🛠  Review: correct; O(n) -> Already optimal.
*/
