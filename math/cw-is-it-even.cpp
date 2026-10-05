// Codewars — Is it even?
// Topic: math | Tags: parity, floating-point
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions July 2024.md — section "Function to return true if even"
/*
Kata description:
In this kata you pass a number (n) into a function. Your code determines if the number passed is even (or not). The function returns either true or false.
Numbers may be positive or negative, integers or floats. Floats with a decimal part not equal to zero are considered UNeven for this kata.
Owner note: fmod (in <cmath>) calculates the floating point remainder.
*/

#include<cmath>

bool is_even(double n)
{
  return fmod(n,2) == 0;
}

/*
💭 First Idea: fmod(n, 2) == 0 for doubles.
🧩 Key Property / Invariant: fmod is exact for doubles, and fmod(-4, 2) is -0.0 which compares equal to 0.
✅ Key insight: Use the floating remainder; % does not work on doubles.
🔁 Recognition cue for next time: "even/odd but input can be a float" -> std::fmod.
⏱  Speed fix for next time: Nothing to speed up.
🛠  Review: correct; O(1) -> Already optimal.
*/
