// Codewars — Over The Road
// Topic: math | Tags: formula
// Complexity (yours): O(1) time, O(1) space

/*
Given your house number `address` and length of street `n`, give the house number on the
opposite side of the street.
ex
1, 3 --> 6
3, 3 --> 4
2, 3 --> 5
3, 5 --> 8
*/

long long over_the_road(long long address, long long n) {
  return n * 2 - address + 1;
}

/*
💭 First Idea: closed-form formula 2n + 1 - address.
🧩 Key Property / Invariant: a house and the one opposite it always add up to 2n + 1.
✅ Key insight: look for the invariant sum of a pair instead of simulating the street (n can be huge).
🔁 Recognition cue for next time: "numbers go up one side and down the other" -> pair sum is constant.
⏱  Speed fix for next time: write out a tiny street (n = 3) and check the sum of each pair.
🛠  Review: correct; O(1) → Already optimal.
*/
