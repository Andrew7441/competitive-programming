// Codewars — Quarter of the year
// Topic: math | Tags: integer-division
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions July 2024.md — section "Function to return quarter of the year"
// Import note: the trailing "return (month +2)/3" was a bare statement outside any function (does not compile); it is now a comment and appears as the optimized version.
/*
Kata description:
Given a month as an integer from 1 to 12, return to which quarter of the year it belongs as an integer number.
Example: month 2 (February) is part of the first quarter; month 6 (June) is the second quarter; month 11 (November) is the fourth quarter.
*/

//Given a month as an integer from 1 to 12, 
//return to which quarter of the year it belongs as an integer number.

int quarter_of(int month){
  if(month>=1 and month<=3){
    return 1;
  }else if(month>=4 and month<=6){
    return 2;
  }else if(month>=7 and month<=9){
    return 3;
  }else if(month>=10 and month<=12){
    return 4;
  }
}

//another code example:

// return (month +2)/3  // [commented out: bare statement outside a function; see optimized below]

// ===================== ⚡ Optimized =====================
// Owner's "another code example" as a real function: ceil(month / 3) = (month + 2) / 3, no branches.
namespace optimized {
int quarter_of(int month) {
  return (month + 2) / 3;
}
}

/*
💭 First Idea: Four range checks, one per quarter.
🧩 Key Property / Invariant: Each quarter is a block of 3 consecutive months.
✅ Key insight: quarter = ceil(month / 3) = (month + 2) / 3.
🔁 Recognition cue for next time: "which block of size k does x fall into" -> (x + k - 1) / k.
⏱  Speed fix for next time: Ceil-division trick: (a + b - 1) / b.
🛠  Review: correct; O(1) -> O(1) branch-free one-liner.
*/
