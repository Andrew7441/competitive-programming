// Codewars — Convert an array of strings to array of numbers
// Topic: strings | Tags: parsing, arrays
// Complexity (yours): O(total length) time, O(n) space

/* May 14
Some really funny web dev gave you a _sequence of numbers_ from his API response as an _sequence of strings_!

You need to cast the whole array to the correct type.

Create the function that takes as a parameter a sequence of numbers represented as strings and outputs a sequence of numbers.

ie:`["1", "2", "3"]` to `[1, 2, 3]`

Note that you can receive floats as well.
*/

#include <vector>
#include <string>

std::vector<float> to_float_array(const std::vector<std::string>& arr) {
  std::vector<float> res;
  
  for(auto i : arr){
    res.push_back(std::stof(i));
  }
  
  return res;
}


/*
💭 First Idea: std::stof on every element.
🧩 Key Property / Invariant: stof parses both ints and floats.
✅ Key insight: Map each element with a parse function.
🔁 Recognition cue for next time: "array of numeric strings -> numbers" -> std::transform + stof.
⏱  Speed fix for next time: Use `const auto& i` and res.reserve(arr.size()).
🛠  Review: correct; O(total length) — Already optimal.
*/
