// Codewars — The highest profit wins!
// https://www.codewars.com/kata/559590633066759614000063
// Topic: arrays | Tags: min-max
// Complexity (yours): O(n) time, O(1) space

/*
Write a function that returns both the minimum and maximum number of the given list/array.
*/

#include <utility>
#include <vector>
#include <algorithm> // added: min_element / max_element (missing in the original note)

std::pair<int, int> min_max(const std::vector<int>& arr)
{
  int min = *min_element(arr.begin(),arr.end());
  int max = *max_element(arr.begin(),arr.end());
  
  return {min,max};
}

/*
💭 First Idea: std::min_element and std::max_element, two passes.
🧩 Key Property / Invariant: the array is non-empty, so dereferencing the iterators is safe.
✅ Key insight: std::minmax_element does both in a single pass (about 1.5n comparisons).
🔁 Recognition cue for next time: "need min AND max" -> minmax_element.
⏱  Speed fix for next time: auto [lo, hi] = std::minmax_element(arr.begin(), arr.end()); return {*lo, *hi};
🛠  Review: correct; O(n) → Already optimal.
*/
