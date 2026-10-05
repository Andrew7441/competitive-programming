// Codewars — Abbreviate a Two Word Name
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(1) extra space
// From: Codewars/Functions.md — section "function converting names into initials"
/*
Kata description:
Convert a two-word name into its initials: "Sam Harris" -> "S.H". Output is two capital letters separated by a dot.
*/

#include <string>  // [added: include missing in the note; needed to compile]
std::string abbrevName(std::string name)
{
  std::string s = "";
  s += toupper(name[0]);
  s += '.';
  s += toupper(name[name.find(' ')+1]);
  return s;
}

/*
💭 First Idea: Take name[0] and the char right after the first space, uppercase both, join with a dot.
🧩 Key Property / Invariant: The second initial is always at index find(' ') + 1.
✅ Key insight: toupper on two known positions is all you need; no splitting required.
🔁 Recognition cue for next time: "initials / abbreviate name" -> find the separator, index around it.
⏱  Speed fix for next time: Write it as one return: {toupper(a), '.', toupper(b)}.
🛠  Review: correct; O(n) for find -> Already optimal.
*/
