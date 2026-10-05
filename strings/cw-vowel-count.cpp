// Codewars — Vowel Count
// Topic: strings | Tags: counting
// Complexity (yours): O(n) time, O(1) space

//feb 1
//Return the number (count) of vowels in the given string.
//We will consider `a`, `e`, `i`, `o`, `u` as vowels for this Kata (but not `y`).
//The input string will only consist of lower case letters and/or spaces.
#include <string>

using namespace std;

int getCount(const string& input){
  int num= 0;
  for(auto i: input){
    if(i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u' ){
      num++;
    }
  }
  return num;
}


// Attempt 2
namespace attempt2 {  // (added wrapper so both attempts compile in one file)
/*
Return the number (count) of vowels in the given string.

We will consider `a`, `e`, `i`, `o`, `u` as vowels for this Kata (but not `y`).

The input string will only consist of lower case letters and/or spaces.
*/
#include <string>

using namespace std;

int getCount(const string& s){
  int num_vowels = 0;
  for(char i: s){
    if(i== 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
      num_vowels++;
    }
  }
  return num_vowels;
}

}  // namespace attempt2

/*
💭 First Idea: Scan the string and count chars in {a,e,i,o,u}.
🧩 Key Property / Invariant: Each char contributes 0 or 1 independently.
✅ Key insight: A single pass with a membership test is all that's needed.
🔁 Recognition cue for next time: "count characters of a kind" -> one loop or std::count_if.
⏱  Speed fix for next time: std::count_if(s.begin(), s.end(), [](char c){ return std::string("aeiou").find(c) != std::string::npos; }).
🛠  Review: correct (both attempts); O(n) — Already optimal.
*/
