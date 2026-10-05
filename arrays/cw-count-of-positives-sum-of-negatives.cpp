// Codewars — Count of positives / sum of negatives
// Topic: arrays | Tags: linear-scan
// Complexity (yours): O(n) time, O(1) extra


/*
Given an array of integers.

Return an array, where the first element is the count of positives numbers and the second element is sum of negative numbers. 0 is neither positive nor negative.

If the input is an empty array or is null, return an empty array.

# Example

For input `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15]`, you should return `[10, -65]`.
*/

#include <vector>

std::vector<int> countPositivesSumNegatives(std::vector<int> i)
{
  if(i.empty()){
    return {};
  }
  int count = 0;
  int sum = 0;
  for(auto x: i){
    if(x>0){
      count++;
    }else{
      sum += x;
    }
  }
  return {count, sum};
}


/*
💭 First Idea: One pass: x > 0 -> count++, else sum += x (zeros add 0).
🧩 Key Property / Invariant: 0 contributes to neither (adding 0 to sum is harmless).
✅ Key insight: Single pass with two accumulators.
🔁 Recognition cue for next time: "two aggregates over one array" -> one loop, two variables.
⏱  Speed fix for next time: Take the vector by const& to avoid the copy.
🛠  Review: correct; O(n) — Already optimal.
*/
