// Codewars — Switcheroo
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(n) space (all attempts)
// Merged: Attempt 1 from Codewars/Functions.md (2024); Attempt 2 from Codewars/2025/February.md; Attempt 3 from Codewars/2025/April.md

/*
Given a string made up of letters a, b, and/or c, switch the position of letters a and b (change a to b and vice versa). Leave any incidence of c untouched.

Example:

'acb' --> 'bca'  
'aabacbaa' --> 'bbabcabb'
*/

#include <string>

// ---------- Attempt 1 (Functions, 2024) ----------
std::string switcheroo(const std::string &s) {
std::string newStr = "";

for(int i = 0; i <= s.length(); i++)
	if(s[i] == 'a')
	  newStr += 'b';

	else if(s[i]=='b')
	  newStr +='a';

	else if(s[i]=='c')
	  newStr +='c';
return newStr;
}

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::string switcheroo(const std::string &s) {
  std::string newstr = "";
  
  for(auto i : s){
    if(i == 'a'){
      newstr += 'b';
    }else if(i == 'b'){
      newstr += 'a';
    }else if(i == 'c'){
      newstr += 'c';
    }
  }
  return newstr;
}
}  // namespace attempt2

// ---------- Attempt 3 (April 2025) ----------
namespace attempt3 {  // (wrapper added in merge so all attempts compile in one file)
std::string switcheroo(const std::string &s) {
  std::string r = "";
  for(int i = 0; i < s.length();i++){
    if(s[i] == 'a'){
      r += 'b';
    }else if(s[i] == 'b'){
      r += 'a';
    }else{
      r += s[i];
    }
  }
  return r;
}
}  // namespace attempt3

/*
💭 First Idea: Build a new string mapping a->b, b->a, c->c (Attempt 3 copies any other char unchanged).
🧩 Key Property / Invariant: Each character is mapped independently, no context needed.
✅ Key insight: Per-character map; a final plain else (Attempt 3) is more robust than silently dropping non a/b/c chars.
🔁 Recognition cue for next time: "swap two letters everywhere" -> per-char map, or modify the string in place.
⏱  Speed fix for next time: Use i < s.size() (Attempt 1's i <= s.length() reads the '\0' at s[size()] for nothing); or take s by value and swap in place.
🛠  Review: Attempt 1 correct (off-by-one bound is harmless), Attempt 2 correct, Attempt 3 correct; O(n) — Already optimal.
*/
