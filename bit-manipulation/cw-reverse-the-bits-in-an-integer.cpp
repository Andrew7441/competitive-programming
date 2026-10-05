// Codewars — Reverse the bits in an integer
// Topic: bit-manipulation | Tags: math
// Complexity (yours): O(log n) time, O(1) space
// From: Codewars/Functions July 2024.md — section "Reverse the bits in an integer"
/*
Kata description:
Write a function that reverses the bits in an integer.
For example, the number 417 is 110100001 in binary. Reversing the binary is 100001011 which is 267.
You can assume that the number is not negative.
*/

unsigned int reverse_bits(unsigned int n) {
    unsigned int rev = 0;
    while (n > 0) {
        rev <<= 1;
        if ((n & 1) == 1)
            rev ^= 1;
        n >>= 1;
    }
    return rev;
}

/*
💭 First Idea: Pop the lowest bit of n and push it onto rev (rev <<= 1, rev |= bit).
🧩 Key Property / Invariant: Only significant bits are reversed (no leading zeros), which the loop on n > 0 gives naturally.
✅ Key insight: rev = (rev << 1) | (n & 1); n >>= 1 until n == 0.
🔁 Recognition cue for next time: "reverse digits/bits" -> pop from one end, push onto the other.
⏱  Speed fix for next time: rev = rev << 1 | (n & 1) is one line.
🛠  Review: correct; O(log n) -> Already optimal.
*/
