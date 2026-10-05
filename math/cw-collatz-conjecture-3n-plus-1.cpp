// Codewars — Collatz Conjecture (3n+1)
// https://www.codewars.com/kata/577a6e90d48e51c55e000217
// Topic: math | Tags: simulation
// Complexity (yours): O(steps) time, O(1) space

/*
Hotpo ("Half Or Triple Plus One"): starting from n, if n is even divide it by 2, otherwise
replace it with 3n + 1. Return how many times the operation is applied until n reaches 1.
hotpo(1) = 0, hotpo(5) = 5 (5 -> 16 -> 8 -> 4 -> 2 -> 1)
*/

unsigned int hotpo(unsigned int n){
  int count = 0;
    if(n == 1) return 0; 
  while(n>1){
    n = n%2 == 0 ? n/2 : 3*n+1;
    ++count;
  }
  return count;
}

/*
💭 First Idea: simulate the Collatz steps and count them.
🧩 Key Property / Invariant: each loop iteration applies exactly one operation; stop when n == 1.
✅ Key insight: no closed form exists — direct simulation is the intended solution.
🔁 Recognition cue for next time: "apply rule until it reaches X, count steps" -> while loop counter.
⏱  Speed fix for next time: the `if(n == 1) return 0;` is redundant — the while condition already handles it.
🛠  Review: correct; O(steps) → Already optimal.
*/
