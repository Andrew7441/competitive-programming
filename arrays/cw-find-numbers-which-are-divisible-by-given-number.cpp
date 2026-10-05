// Codewars — Find numbers which are divisible by given number
// Topic: arrays | Tags: filtering, math
// Complexity (yours): O(n) time, O(n) space

/*
Complete the function which takes two arguments and returns all numbers which are divisible by
the given divisor. First argument is an array of `numbers` and the second is the `divisor`.

[1, 2, 3, 4, 5, 6], 2 --> [2, 4, 6]
*/

#include <vector> // added: std::vector (missing in the original note)

std::vector<int> divisible_by(std::vector<int> numbers, int divisor)
{
  std::vector<int> res;
  
  for(int i: numbers){
    if(i % divisor == 0){
      res.push_back(i);
    }
  }
  return res;

}

/*
💭 First Idea: loop over the numbers and keep those with i % divisor == 0.
🧩 Key Property / Invariant: output keeps the original order of the kept elements.
✅ Key insight: plain filter; std::copy_if(..., std::back_inserter(res), pred) is the library version.
🔁 Recognition cue for next time: "return all elements that satisfy X" -> filter (copy_if / remove_if on a copy).
⏱  Speed fix for next time: take the vector by const& (no copy) and res.reserve(numbers.size()).
🛠  Review: correct; O(n) → Already optimal.
*/
