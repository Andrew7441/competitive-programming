// Codewars — Highest and Lowest
// Topic: strings | Tags: parsing, min-max
// Complexity (yours): O(n) time, O(1) extra space
// From: Codewars/Functions.md — section "Practice"
/*
Kata description:
You are given a string of space-separated numbers and have to return the highest and lowest number, as a string "max min".
Example: "1 2 3 4 5" -> "5 1"; "1 9 3 4 -5" -> "9 -5". All numbers are valid ints; there is at least one number.
*/

#include <string>
#include <sstream>
#include <limits>

std::string highAndLow(const std::string& numbers){
  std::stringstream ss(numbers); // splits string into individual numbers
  int temp; // temp variable to compate
  int max = std::numeric_limits<int>::min();
  int min = std::numeric_limits<int>::max(); 
  
  while (ss >> temp) {
    min = (temp < min) ? temp : min;
    max = (temp > max) ? temp : max;
  };
  return std::to_string(max) + " " + std::to_string(min);
}

/*
💭 First Idea: Parse with stringstream >> int, tracking running min and max.
🧩 Key Property / Invariant: Start max at INT_MIN and min at INT_MAX so the first number sets both.
✅ Key insight: One pass with a stream extractor does parsing and min/max together.
🔁 Recognition cue for next time: "numbers inside a string" -> std::stringstream >> x loop.
⏱  Speed fix for next time: std::min/std::max are cleaner than the ternaries.
🛠  Review: correct; O(n) -> Already optimal.
*/
