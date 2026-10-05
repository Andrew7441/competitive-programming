// Codewars — Find the nth Digit of a Number
// Topic: math | Tags: digits, strings
// Complexity (yours): O(d) time, O(d) space
// From: Codewars/Functions July 2024.md — section "Function to return the Nth digit of the number counting from the right to left"
// Import note: closing brace of findDigit was missing in the note; added so it compiles.
/*
Kata description:
Complete the function that takes two numbers as input, num and nth, and returns the nth digit of num (counting from right to left).
- If num is negative, ignore its sign and treat it as positive.
- If nth is not positive, return -1.
- If nth is greater than the number of digits, return 0.
Examples: findDigit(5673, 4) -> 5, findDigit(129, 2) -> 2, findDigit(-2825, 3) -> 8, findDigit(0, 20) -> 0, findDigit(65, 0) -> -1.
*/

#include <iostream>

int findDigit(int num, int nth) {
    if (nth <= 0) {
        return -1; // if nth smaller than 0 return -1
    }
  
    std::string numStr = std::to_string(std::abs(num)); // return absolute value 
    
    if (nth > numStr.length()) { // if nth larger than the length of nums return 0
        return 0;
    }
    
    char nthDigit = numStr[numStr.length() - nth]; // calculate the nth digit from the right

    return nthDigit - '0';
}  // [added: closing brace missing in the note]

/*
💭 First Idea: to_string(abs(num)) and index length - nth.
🧩 Key Property / Invariant: The nth digit from the right is at index len - nth.
✅ Key insight: Handle the edge cases (nth <= 0, nth > len) before indexing.
🔁 Recognition cue for next time: "k-th digit from the right" -> divide by 10 (k-1) times then % 10, or string index len-k.
⏱  Speed fix for next time: Arithmetic version: for (k-1 times) num /= 10; return num % 10; no string needed.
🛠  Review: correct; O(d) -> Already optimal. (std::abs(INT_MIN) would overflow; not in tests.)
*/
