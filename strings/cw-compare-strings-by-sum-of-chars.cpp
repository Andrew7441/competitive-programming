// Codewars — Compare Strings by Sum of Chars
// https://www.codewars.com/kata/576bb3c4b1abc497ec000065
// Topic: strings | Tags: validation, implementation
// Complexity (yours): O(|s1| + |s2|) time; O(1) extra (Attempt 1) / O(|s1| + |s2|) extra (Attempt 2) space
// ⚠️ Review: Attempt 1 uppercases a copy (for(char c : s1) c = ...) and does not zero strings with non-letters; Attempt 2 returns true whenever one string is empty and drops non-letters instead of treating the whole string as empty; see corrected version below.
// Merged: Attempt 1 from Codewars/Functions July 2024.md; Attempt 2 from Codewars/September 2024.md

//Compare two strings by comparing the sum of their values (ASCII character code).

//For comparing treat all letters as UpperCase
//null/NULL/Nil/None should be treated as empty strings
//If the string contains other characters than letters, treat the whole string as it would be empty
//Your method should return true, if the strings are equal and false if they are not equal.
// Examples: "AD","BC" -> true; "AD","DD" -> false; "gf","FG" -> true; "zz1","" -> true;
//           "ZzZz","ffPFF" -> true; "kl","lz" -> false; null,"" -> true

#include <string>
#include <string.h>
#include <cctype>
#include <iostream>

// ---------- Attempt 1 (Functions July 2024) ----------
bool compare(std::string s1, std::string s2)
{
    if(s1.empty() and s2.empty()){
      return true;
    }
  
  for(char c:s1){
    c = std::toupper(c);
  }
  
  for(char s:s2){
    s = std::toupper(s);
  }
  
  int sum1 = 0;
  int sum2 = 0;
  
  for(char c:s1){
    if(isalpha(c)){
      sum1 += static_cast<int>(c);
    }
  }
  
  for(char c:s2){
    if(isalpha(c)){
      sum2 += static_cast<int>(c);
    }
  }
  return sum1 == sum2;
}

// ---------- Attempt 2 (September 2024) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
bool compare(std::string s1, std::string s2) {
   
    if (s1.empty() or s2.empty()) {
        return true;
    }

    std::string upper_s1, upper_s2;
    for (char c : s1) {
        if (std::isalpha(c)) {
            upper_s1 += std::toupper(c);
        }
    }
    for (char c : s2) {
        if (std::isalpha(c)) {
            upper_s2 += std::toupper(c);
        }
    }

    int sum1 = 0, sum2 = 0;
    for (char c : upper_s1) {
        sum1 += static_cast<int>(c);
    }
    for (char c : upper_s2) {
        sum2 += static_cast<int>(c);
    }

    return sum1 == sum2;
}
}  // namespace attempt2

// ===================== ⚡ Corrected =====================
// Bug 1: compare("", "AD") must be false (0 vs 133), yours returns true.
// Bug 2: compare("ZZ1", "ZZ") must be false ("ZZ1" counts as empty -> 0), yours returns true.
// Fix: value(s) = 0 if s contains any non-letter, else sum of toupper(c); compare the two values.
namespace optimized {
bool compare(std::string s1, std::string s2) {
    auto value = [](const std::string& s) {
        long long sum = 0;
        for (unsigned char c : s) {
            if (!std::isalpha(c)) return 0LL;      // any non-letter -> whole string counts as empty
            sum += std::toupper(c);
        }
        return sum;
    };
    return value(s1) == value(s2);
}
}

/*
💭 First Idea: Uppercase the letters, sum ASCII codes of both strings, compare (Attempt 1 with an empty&&empty shortcut, Attempt 2 with an empty||empty shortcut).
🧩 Key Property / Invariant: Each string maps to ONE number (0 if empty or it contains any non-letter, else sum of toupper(c)); answer is value(s1) == value(s2).
✅ Key insight: An invalid string is "empty" as a whole — validate first, then sum; never filter characters out.
🔁 Recognition cue for next time: "treat the whole string as X if ..." -> a helper that returns early for that case.
⏱  Speed fix for next time: for (char c : s) gives a copy — use char& to modify; and run the spec examples ("gf","FG"; "zz1",""; "","AD") before submitting.
🛠  Review: Attempt 1 wrong ("gf","FG" -> false: toupper on a copy), Attempt 2 wrong ("","AD" -> true; "ZZ1","ZZ" -> true); O(n) -> corrected O(n).
*/
