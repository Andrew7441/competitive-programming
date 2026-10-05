// Codewars — What's the real floor?
// Topic: implementation | Tags: math
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions.md — section "Function to convert floors based on the american system"
/*
Kata description:
Americans number floors oddly: the ground floor is "1" and there is no 13th floor. Given an American floor number, return the European floor:
- 1 -> 0 (ground floor), 2..13 -> f - 1, above 13 -> f - 2 (the missing 13th floor),
- basement (0 or negative) floors stay the same.
Examples: 1 -> 0, 0 -> 0, 5 -> 4, 15 -> 13, -3 -> -3.
*/

int getRealFloor(int f) {
  
  if(f == 1){
    return 0;
  }else if(f>1 and f<=13){
    return f-1;
  }else if(f>13){
    return f-2;
  }else 
    return f;
} 

//function that given a floor in the american system returns the floor 
//in the european system.

/*
💭 First Idea: Case split on f: 1, 2..13, >13, and <=0.
🧩 Key Property / Invariant: Each threshold (ground floor, missing 13) removes one from the count.
✅ Key insight: f <= 0 ? f : f > 13 ? f - 2 : f - 1 (the f == 1 case is covered by f - 1).
🔁 Recognition cue for next time: "piecewise rules" -> write the ranges in order and merge the ones with the same formula.
⏱  Speed fix for next time: Merge f == 1 into the f - 1 branch.
🛠  Review: correct; O(1) -> Already optimal.
*/
