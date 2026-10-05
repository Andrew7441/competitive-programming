// Codewars — L1: Set Alarm
// Topic: implementation | Tags: boolean-logic
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions July 2024.md — section "Function should return true if you are employed and not on vacation"
/*
Kata description:
Write a function set_alarm that receives two parameters, employed and vacation (both bool). Return true if you are employed and not on vacation (you need an alarm to wake up for work), false otherwise.
test cases:
employed | vacation
true     | true     => false
true     | false    => true
false    | true     => false
false    | false    => false
*/

bool set_alarm(const bool& employed,const bool& vacation){
  if(employed and vacation){
    return false;
  }else if(employed){
    return true;
  }else{
    return false;
  }
}

// ===================== ⚡ Optimized =====================
// The truth table is exactly "employed AND NOT vacation".
namespace optimized {
bool set_alarm(const bool& employed, const bool& vacation) {
  return employed && !vacation;
}
}

/*
💭 First Idea: if/else chain over the truth table.
🧩 Key Property / Invariant: Only one row of the table is true: (true, false).
✅ Key insight: A truth table with a single true row is an AND of literals: employed && !vacation.
🔁 Recognition cue for next time: "return true only if A and not B" -> write the boolean expression, not branches.
⏱  Speed fix for next time: Read the truth table and write the expression directly.
🛠  Review: correct; O(1) -> simpler O(1) one-liner.
*/
