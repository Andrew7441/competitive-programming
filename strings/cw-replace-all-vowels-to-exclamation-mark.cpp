// Codewars — Exclamation marks series #11: Replace all vowel to exclamation mark in the sentence
// Topic: strings | Tags: regex
// Complexity (yours): O(n) time, O(n) space
// From: Codewars/Functions.md — section "Function Replace vowels with ! . regex_replace is a function that performs subsitutions"
/*
Kata description:
Replace every vowel (aeiouAEIOU) in the sentence with "!".
Owner note: regex_replace is a function that performs substitutions.
*/

#include <string>
#include <regex>

using namespace std;

string replace(const string &s)
{
  return regex_replace(s, regex("[aeiouAEIOU]"), "!");
}

/*
💭 First Idea: std::regex_replace with the character class [aeiouAEIOU] -> "!".
🧩 Key Property / Invariant: Each character is replaced independently; length never changes.
✅ Key insight: A character class regex does the whole job in one call.
🔁 Recognition cue for next time: "replace every char of a set" -> regex_replace or a simple loop with a lookup string.
⏱  Speed fix for next time: std::regex is slow to construct; a manual loop with strchr("aeiouAEIOU", c) is faster for huge inputs.
🛠  Review: correct; O(n) -> Already optimal.
*/
