// Codewars — Invert values
// Topic: arrays | Tags: implementation
// Complexity (yours): O(n) time, O(n) space
// From: Codewars/Functions July 2024.md — section "Function to return additive inverse of each. Each positive becomes negatives, and the negatives become positives."
/*
Kata description:
Given a set of numbers, return the additive inverse of each. Each positive becomes negative, and the negatives become positive.
Example: [1,2,3,4,5] -> [-1,-2,-3,-4,-5]; [1,-2,3,-4,5] -> [-1,2,-3,4,-5]; [] -> [].
*/

#include <vector>

std::vector<int> invert(std::vector<int> values)
{
    std::vector<int> result;
  
  for(int i:values){
    result.push_back(-i);
  }
  return result;
}

/*
💭 First Idea: Push -i for every element.
🧩 Key Property / Invariant: Element-wise map, order preserved.
✅ Key insight: Could negate in place since values is passed by value.
🔁 Recognition cue for next time: "apply f to each element" -> loop or std::transform.
⏱  Speed fix for next time: for (int& v : values) v = -v; return values;
🛠  Review: correct; O(n) -> Already optimal.
*/
