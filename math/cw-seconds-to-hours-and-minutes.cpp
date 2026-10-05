// Codewars — Seconds to hours and minutes (to_time)
// Topic: math | Tags: time-conversion
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions July 2024.md — section "(untitled: "Create a function that takes an integer argument of seconds...")"
/*
Kata description:
Create a function that takes an integer argument of seconds and converts the value into a string describing how many hours and minutes comprise that many seconds.
Any remaining seconds left over are ignored.
Note: the string output needs to be in the specific form "X hour(s) and X minute(s)".
For example:
3600 --> "1 hour(s) and 0 minute(s)"
3601 --> "1 hour(s) and 0 minute(s)"
3500 --> "0 hour(s) and 58 minute(s)"
323500 --> "89 hour(s) and 51 minute(s)"
*/

#include <string>

std::string to_time(unsigned seconds) {
  int min  = seconds / 60;
  int hour = min / 60;
  
  return std::to_string(hour) + " hour(s) and " + std::to_string(min%60) + " minute(s)";
}

/*
💭 First Idea: minutes = seconds / 60, hours = minutes / 60, print hours and minutes % 60.
🧩 Key Property / Invariant: Integer division drops the leftover seconds automatically.
✅ Key insight: Split with / and % by 60.
🔁 Recognition cue for next time: "seconds to h/m/s" -> /3600, /60 % 60, % 60.
⏱  Speed fix for next time: Nothing to speed up.
🛠  Review: correct; O(1) -> Already optimal.
*/
