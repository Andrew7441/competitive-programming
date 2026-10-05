// Codewars — Jumping Number (Special Numbers Series #4)
// Topic: math | Tags: digits
// Complexity (yours): O(d) time, O(d) space
// From: Codewars/Functions July 2024.md — section "(untitled: "Jumping number is the number that All adjacent digits in it differ by 1")"
/*
Kata description:
A Jumping number is a number in which all adjacent digits differ by 1 (the difference between 9 and 0 is NOT considered 1). All single-digit numbers are jumping numbers.
Task: given a positive number, return "Jumping!!" if it is a jumping number, otherwise "Not!!".
Examples: 9 -> "Jumping!!", 79 -> "Not!!", 23 -> "Jumping!!", 556847 -> "Not!!", 4343456 -> "Jumping!!", 89098 -> "Not!!".
*/

#include <string>

using namespace std; 
string jumpingNumber(int number) {
    string numStr = to_string(number);
    int n = numStr.size();

    for (int i = 1; i < n; ++i) {
        int digit1 = numStr[i - 1] - '0'; // Convert char to integer
        int digit2 = numStr[i] - '0';

        if (abs(digit1 - digit2) != 1) {
            return "Not!!"; // Updated return value
        }
    }

    return "Jumping!!";
}

/*
💭 First Idea: to_string, then check |d[i] - d[i-1]| == 1 for every adjacent pair.
🧩 Key Property / Invariant: Single digits have no adjacent pair, so they are jumping.
✅ Key insight: Early exit on the first bad pair.
🔁 Recognition cue for next time: "property of adjacent digits" -> loop i = 1..len-1 comparing s[i] and s[i-1].
⏱  Speed fix for next time: Starting at i = 1 (as you did) avoids the s[-1] bug.
🛠  Review: correct; O(d) -> Already optimal.
*/
