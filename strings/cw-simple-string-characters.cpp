// Codewars — Simple string characters
// https://www.codewars.com/kata/5a29a0898f27f2d9c9000058
// Topic: strings | Tags: counting, cctype
// Complexity (yours): O(n) time, O(1) extra space (both attempts)
// Merged: Attempt 1 from Codewars/Functions July 2024.md; Attempt 2 (+ best_practice) from Codewars/2025/March/March 3-9.md
// Import note: Attempt 1 closing brace and <vector>/<string> includes were missing in the notes; added.

/*
given a string, your task will be to return a list of ints detailing the count of uppercase letters, lowercase, numbers and special characters (everything else), as follows.

The order is: uppercase letters, lowercase letters, numbers and special characters.
"*'&ABCDabcde12345" --> [ 4, 5, 5, 3 ]
*/

#include <vector>
#include <string>
#include <cctype>

// ---------- Attempt 1 (Functions July 2024) ----------
std::vector<int> solve(std::string s){
  std::vector<int> count(4,0);
    
    
  for(char c:s){
    if(std::isupper(c)){
      count[0]++;
    }else if(std::islower(c)){
      count[1]++;
    }else if(std::isdigit(c)){
      count[2]++;
    }else{
      count[3]++;
    }
  }
  return count;
}  // [added: closing brace missing in the note]

// ---------- Attempt 2 (March 3-9, 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::vector<int> solve(std::string s){
  std::vector<int> count(4,0);
  
  for(auto i: s){
    if(std::isupper(i)){
      count[0]++;
    }else if(std::islower(i)){
      count[1]++;
    }else if(std::isdigit(i)){
      count[2]++;
    }else{
      count[3]++;
    }
  }
  return count;
}
}  // namespace attempt2

//BEST PRACTICES:

namespace best_practice {
std::vector<int> solve(std::string s){
    std::vector <int> v = {0,0,0,0};
    for(char& ch : s) {
        if (isupper(ch)) v[0]++;
        else if (islower(ch)) v[1]++;
        else if (isdigit(ch)) v[2]++;
        else v[3]++;
    }
    return v;
}
} // namespace best_practice

/*
💭 First Idea: One pass, classify each char with isupper / islower / isdigit / else into 4 counters (same both times).
🧩 Key Property / Invariant: The four classes are disjoint and cover every char, so the counts sum to s.size().
✅ Key insight: An if / else-if chain ending in a plain else = the "everything else" bucket.
🔁 Recognition cue for next time: "count chars by category" -> fixed-size counter array + <cctype>.
⏱  Speed fix for next time: Take the string by const&; cast to unsigned char before the cctype functions.
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(n) — Already optimal.
*/
