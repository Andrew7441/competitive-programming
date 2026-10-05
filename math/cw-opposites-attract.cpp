// Codewars — Opposites Attract
// Topic: math | Tags: parity
// Complexity (yours): O(1)

// NOTE (reorg): the bare text line "best practic:" was prefixed with "// " so the file compiles.
/*
Timmy & Sarah think they are in love, but around where they live, they will only know once they pick a flower each. If one of the flowers has an even number of petals and the other has an odd number of petals it means they are in love.

Write a function that will take the number of petals of each flower and return true if they are in love and false if they aren't.
*/
bool lovefunc(int f1, int f2) {
  if((f1 % 2 == 0 && f2 % 2 != 0) or (f2 % 2 == 0 && f1 % 2 != 0))
    return true;
  else
    return false;
  
  
}
// best practic:

namespace best_practice {  // (added wrapper: same signature as yours, would be a redefinition)
bool lovefunc(int a, int b) {
  return (a + b) % 2;
}
}  // namespace best_practice

/*
💭 First Idea: Check (even, odd) or (odd, even) explicitly.
🧩 Key Property / Invariant: One even + one odd ⇔ the sum is odd.
✅ Key insight: return (a + b) % 2 != 0; — parity of a sum.
🔁 Recognition cue for next time: "exactly one of two numbers is odd" -> (a + b) odd, or (a ^ b) & 1.
⏱  Speed fix for next time: Return the boolean expression directly instead of if/else true/false.
🛠  Review: correct; O(1) — Already optimal.
*/
