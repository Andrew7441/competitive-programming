// Codewars — Find The Parity Outlier
// Topic: arrays | Tags: math, parity
// Complexity (yours): O(n) time, O(1) space
// NOTE (reorg): added <vector> — missing in the original and needed to compile outside Codewars.
#include <vector>

/*
You are given an array (which will have a length of at least 3, but could be very large) containing integers. The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer `N`. Write a method that takes the array as an argument and returns this "outlier" `N`.
## Examples
[2, 4, 0, 100, 4, 11, 2602, 36] -->  11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21] --> 160 (the only even number)
*/
int FindOutlier(std::vector<int> arr)
{
  int even, odd;
  int evencount = 0;
  int oddcount = 0;
  
  for(auto i : arr){
    i%2==0 ? (evencount++, even = i) : (oddcount++, odd = i);
  }
  
  return evencount < oddcount ? even : odd;
}

/*
💭 First Idea: Count evens and odds (remembering the last of each), return the rarer one.
🧩 Key Property / Invariant: Exactly one element has the minority parity.
✅ Key insight: Parity of the first 3 elements already tells you the majority; then return the first mismatch.
🔁 Recognition cue for next time: "one element differs in parity" -> majority from first 3, then scan.
⏱  Speed fix for next time: Early-exit version: int maj = (abs(a[0]%2)+abs(a[1]%2)+abs(a[2]%2)) >= 2; return first x with abs(x%2) != maj.
🛠  Review: correct (i%2 == -1 for negative odds still lands in the odd branch); O(n) — Already optimal.
*/
