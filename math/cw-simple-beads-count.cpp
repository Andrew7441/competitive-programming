// Codewars — Simple beads count
// Topic: math | Tags: formula
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions 2.md — section "function that calculates red beads between blue beads"
/*
Kata description:
Two red beads are placed between every two blue beads. There are N blue beads. After looking at the arrangement below, work out the number of red beads.
@ @@ @ @@ @ @@ @ @@ @ @@ @   (@ = blue bead, @@ = two red beads)
N = 0 or 1 -> 0 red beads.
*/

//Two red beads are placed between every two blue beads. \
//There are N blue beads. After looking at the arrangement below 
//work out the number of red beads.

unsigned int countRedBeads( unsigned int n ) {
  if(n<2)
    return 0;
  return (n-1)*2;
} 

/*
💭 First Idea: There are n - 1 gaps between n blue beads, each holding 2 red beads.
🧩 Key Property / Invariant: Gaps = n - 1 (only when n >= 2).
✅ Key insight: Answer = 2(n - 1) for n >= 2, else 0.
🔁 Recognition cue for next time: "things between things" -> count the gaps (n - 1).
⏱  Speed fix for next time: Guard n < 2 first: unsigned n - 1 underflows at n = 0.
🛠  Review: correct; O(1) -> Already optimal. (Trailing \\ in the first comment line continues the comment; harmless, -Wcomment warns.)
*/
