// Codewars — Beginner Series #1 School Paperwork
// Topic: math | Tags: implementation
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions July 2024.md — section "Function to calculate how many blank pages you need"
/*
Kata description:
Your classmates asked you to copy some paperwork for them. You know that there are n classmates and the paperwork has m pages.
Your task is to calculate how many blank pages you need. If n < 0 or m < 0 return 0.
Example: n=5, m=5 -> 25; n=-5, m=5 -> 0.
*/

int paperwork(int n, int m){
  if(n<0 or m<0){
    return 0;
  }
    return n*m;
}

/*
💭 First Idea: Return 0 for negative inputs, else n*m.
🧩 Key Property / Invariant: Negative counts are invalid -> 0.
✅ Key insight: Guard then multiply.
🔁 Recognition cue for next time: "count with invalid negatives" -> guard clause first.
⏱  Speed fix for next time: return (n < 0 || m < 0) ? 0 : n * m;
🛠  Review: correct; O(1) -> Already optimal.
*/
