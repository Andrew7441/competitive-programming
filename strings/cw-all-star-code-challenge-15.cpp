// Codewars — All Star Code Challenge #15
// Topic: strings | Tags: rotation
// Complexity (yours): O(n^2) time (output itself is n strings of length n), O(n^2) space

/*
This Kata is intended as a small challenge for my students.

Your family runs a shop and have just brought a Scrolling Text Machine to help get some more
business.

The scroller works by replacing the current text string with a similar text string, but with the
first letter shifted to the end; this simulates movement.

Create a function named rotate() that accepts a string argument and returns an array of strings
with each letter from the input string being rotated to the end.

Examples:
rotate("Hello") // => {"elloH", "lloHe", "loHel", "oHell", "Hello"}

Note:
- The original string should be included in the output array.
- The order matters. Each element of the output array should be the rotated version of the previous element.
- The output array SHOULD be the same length as the input string.
- The function should return an empty array with an empty string ('') as input.
*/

// Attempt 1 (September 2024)
#include <string>
#include <vector>
#include <sstream>
std::vector<std::string> rotate(const std::string& s) {
  std::vector<std::string> res;
  if(s.empty()){
    return res;
  }
  
  std::string r = s;
  
  for(size_t i=0;i<s.length();i++){
    r = r.substr(1) + r[0];
    res.push_back(r);
  }
  
  return res;
}
//OR
// Attempt 2 (September 2024)
namespace attempt2 {
std::vector<std::string> rotate(const std::string& s) {
  std::vector<std::string> arr;
  for(int i = 0; i < s.size(); i++){
    arr.push_back(s.substr(i + 1, s.size()) + s.substr(0, i + 1));
  }
  return arr;
}
} // namespace attempt2

// Attempt 3 (March 2025)
#include <string>
#include <vector>
#include <sstream>
namespace attempt3 {
std::vector<std::string> rotate(const std::string& s){
  std::vector<std::string> res;
  if(s.empty()){
    return res;
  }
  
  std::string r = s;
  
  for(size_t i = 0; i < s.length();i++){
    r = r.substr(1) + r[0];
    res.push_back(r);
  }
  
  return res;
}
} // namespace attempt3

/*
💭 First Idea: repeatedly move the first char of the current string to the end and record each result.
🧩 Key Property / Invariant: the i-th rotation is s.substr(i+1) + s.substr(0, i+1); after n rotations you are back at s.
✅ Key insight: rotations can be built directly from substrings (attempt 2) or with std::rotate on a copy.
🔁 Recognition cue for next time: "all rotations of a string" -> substr pair, or (s + s).substr(i, n).
⏱  Speed fix for next time: <sstream> is not needed; reserve(s.size()) on the result.
🛠  Review: correct (all three attempts); O(n^2) is the output size → Already optimal.
*/
