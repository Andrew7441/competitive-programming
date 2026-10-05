// Codewars — altERnaTIng cAsE <=> ALTerNAtiNG CaSe
// Topic: strings | Tags: cctype, implementation
// Complexity (yours): O(n·k) time (k = specialChars length) for Attempts 1 and 3, O(n) for Attempt 2; O(n) space
// ⚠️ Review: Attempts 1 and 3 silently drop any char not in the hard-coded whitelist (e.g. ' - " ( ) _ @ #); Attempt 2 is correct.
// Merged: Attempts 1-2 from Codewars/September 2024.md; Attempt 3 from Codewars/2025/July/Practice.md

// NOTE (reorg): the line starting "As usual" was bare text in the original block; prefixed with "// " so the file compiles.
/*
Define `String.prototype.toAlternatingCase` (or a similar function/method _such as_ `to_alternating_case`/`toAlternatingCase`/`ToAlternatingCase` in your selected language; **see the initial solution for details**) such that each lowercase letter becomes uppercase and each uppercase letter becomes lowercase. For example:

```javascript
"hello world".toAlternatingCase() === "HELLO WORLD"
"HELLO WORLD".toAlternatingCase() === "hello world"
"hello WORLD".toAlternatingCase() === "HELLO world"
"HeLLo WoRLD".toAlternatingCase() === "hEllO wOrld"
"12345".toAlternatingCase()       === "12345"                   // Non-alphabetical characters are unaffected
"1a2b3c4d5e".toAlternatingCase()  === "1A2B3C4D5E"
"String.prototype.toAlternatingCase".toAlternatingCase() === "sTRING.PROTOTYPE.TOaLTERNATINGcASE"

*/
// As usual, your function/method should be pure, i.e. it should **not** mutate the original string.

#include <string>
#include <iostream>
#include <cctype>

// ---------- Attempt 1 (September 2024) ----------
std::string to_alternating_case(const std::string& str)
{
  std::string specialChars = ".,=,,>,<,/,;,?,:,!";
  std::string res = "";
	for(char c: str){
    if(std::isupper(c)){
      
      res += std::tolower(c);
      
    }else if(std::islower(c)){
      
      res += std::toupper(c);
      
    }else if(c == ' ' or c== '  '){
      
      res += ' ';
      
    }else if(std::isdigit(c)){
      
      res += c;
      
    }else if(specialChars.find(c) != std::string::npos){
      
      res+= c;
      
    }
  }
  return res;
}

// ---------- Attempt 2 (September 2024) ----------
//simpler way to do it
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::string to_alternating_case(std::string str)
{
  for(auto& ch : str)
  {
    ch = std::islower(ch) ? std::toupper(ch) : std::tolower(ch);
  }
  return str;
}
}  // namespace attempt2

// ---------- Attempt 3 (July 2025 Practice) ----------
namespace attempt3 {  // (wrapper added in merge so all attempts compile in one file)
std::string to_alternating_case(const std::string& str)
{
  std::string specialChars = ".,=,,>,<,/,;,?,:,!";
  std::string res = "";
	for(auto c: str){
    if(std::isupper(c)){
      res += std::tolower(c);
    }else if(std::islower(c)){
      res += std::toupper(c);
  }else if(c == ' '){
      res += ' ';
  }else if(std::isdigit(c)){
      res += c;
  }else if(specialChars.find(c) != std::string::npos){
      res+= c; 
  }
}
  return res;
}
}  // namespace attempt3

// ===================== ⚡ Optimized =====================
// Fix: every non-letter is copied unchanged; toupper/tolower already leave non-letters alone.
namespace optimized {
std::string to_alternating_case(const std::string& str)
{
  std::string res = str;
  for (char& c : res) {
    unsigned char u = static_cast<unsigned char>(c);
    c = std::isupper(u) ? static_cast<char>(std::tolower(u)) : static_cast<char>(std::toupper(u));
  }
  return res;
}
}

/*
💭 First Idea: Case-by-case: flip letters, copy spaces/digits/listed punctuation (Attempts 1 and 3); flip in place with one ternary (Attempt 2).
🧩 Key Property / Invariant: Only letters change; tolower/toupper are the identity on non-letters, so every other char must be copied unchanged.
✅ Key insight: "flip letters, keep everything else" = one ternary per char; never whitelist the "other" chars.
🔁 Recognition cue for next time: "non-alphabetical characters are unaffected" -> rely on tolower/toupper leaving them alone.
⏱  Speed fix for next time: Attempt 1's `c == '  '` is a multi-char literal (never true) — read -Wall warnings; reuse Attempt 2 instead of rewriting the whitelist.
🛠  Review: Attempt 1 wrong (drops non-whitelisted chars), Attempt 2 correct, Attempt 3 wrong (same whitelist bug again); O(n) -> optimized O(n).
*/
