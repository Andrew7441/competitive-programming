// Codewars — Convert an array of strings to array of numbers
// Topic: strings | Tags: parsing
// Complexity (yours): O(total length) time, O(n) space
// From: Codewars/Functions 2.md — section "function that takes as a parameter a sequence of numbers represented as strings and outputs a sequence of numbers. Can receive floats"
/*
Kata description:
Write a function that takes a sequence of numbers represented as strings and outputs the corresponding sequence of numbers (they may be floats).
Example: ["1", "2", "3"] -> [1, 2, 3]; ["1.5", "-2"] -> [1.5, -2].
*/

#include <vector>
#include <string>
#include <sstream>
#include <vector>

std::vector<float> to_float_array(const std::vector<std::string>& arr) {
	std::vector<float> numbers;
	
	for(const auto& array: arr)
		numbers.push_back(std::stof(array));
	
	return numbers;
}

/*
💭 First Idea: Loop and push_back std::stof(s) for each string.
🧩 Key Property / Invariant: stof parses ints and floats alike.
✅ Key insight: One conversion per element.
🔁 Recognition cue for next time: "strings to numbers" -> stoi / stoll / stof / stod.
⏱  Speed fix for next time: numbers.reserve(arr.size()) before the loop.
🛠  Review: correct; O(total length) -> Already optimal.
*/
