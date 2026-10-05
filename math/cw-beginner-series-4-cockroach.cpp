// Codewars — Beginner Series #4 Cockroach
// Topic: math | Tags: unit-conversion
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions.md — section "function which takes its speed in km per hour and returns it in cm per second, rounded down to the integer (= floored)."
/*
Kata description:
The cockroach is one of the fastest insects. Write a function which takes its speed in km per hour and returns it in cm per second, rounded down to the integer (floored).
Example: 1.08 km/h -> 30 cm/s.
*/

#include<cmath>
int cockroach_speed(double s)
{
    return std::floor(s * 100000 / 3600);
}

/*
💭 First Idea: 1 km/h = 100000 cm / 3600 s, multiply and floor.
🧩 Key Property / Invariant: Multiply before dividing to keep floating error small.
✅ Key insight: Unit conversion factor 100000/3600 = 250/9.
🔁 Recognition cue for next time: "convert units and floor" -> one formula + std::floor.
⏱  Speed fix for next time: Write s * 250 / 9 if you want a smaller constant.
🛠  Review: correct; O(1) -> Already optimal.
*/
