// Codewars — Keep up the hoop
// Topic: implementation | Tags: conditionals
// Complexity (yours): O(1) time, O(1) space (both attempts)
// Merged: Attempt 1 from Codewars/Functions 2.md (2024); Attempt 2 from Codewars/2025/March/March 17-22.md

/*
Alex just got a new hula hoop, he loves it but feels discouraged because his little brother is better than him.

Write a program where Alex can input (`n`) how many times the hoop goes round and it will return him an encouraging message:

- If Alex gets 10 or more hoops, return the string `"Great, now move on to tricks"`.
- If he doesn't get 10 hoops, return the string `"Keep at it until you get it"`.
*/

#include <string>

// ---------- Attempt 1 (Functions 2, 2024) ----------
std::string hoop_count(unsigned n) {
   if(n>=10){
     return "Great, now move on to tricks";
   }else{
     return "Keep at it until you get it";
   }
}

// ---------- Attempt 2 (March 17-22, 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::string hoop_count(unsigned n){
  return n >= 10 ? "Great, now move on to tricks" : "Keep at it until you get it";
}
}  // namespace attempt2

/*
💭 First Idea: if/else on n >= 10 (Attempt 1), then the same as a ternary (Attempt 2).
🧩 Key Property / Invariant: Only the threshold 10 matters.
✅ Key insight: One comparison; the ternary is the cleanest form.
🔁 Recognition cue for next time: "return message A or B by threshold" -> ternary.
⏱  Speed fix for next time: Attempt 2 is already the one-liner.
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(1) — Already optimal.
*/
