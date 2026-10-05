// Codewars — Number of Decimal Digits
// Topic: math | Tags: digits
// Complexity (yours): O(log10 n) time, O(1) space (both attempts)
// Merged: Attempt 1 from Codewars/Functions 2.md (2024); Attempt 2 from Codewars/2025/July/Practice.md

/*
Determine the total number of digits in the integer (`n>=0`) given as input to the function. For example, 9 is a single digit, 66 has 2 digits and 128685 has 6 digits. Be careful to avoid overflows/underflows.

All inputs will be valid.
*/

#include <cstdint>
#include <cmath>
#include <stdint.h>

// ---------- Attempt 1 (Functions 2, 2024) ----------
int digits(uint64_t n) {
    if (n == 0) {
        return 1;
    }
    uint64_t x = n;
    int count = 0;

    while (x > 0) { // while the input in x is larger than 10, ex=20
        x /= 10; // divide by until x becomes 0
        count++; // increment 1 each time we divide
    }
    return count;
}

// ---------- Attempt 2 (July 2025 Practice) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
int digits(uint64_t n) {
  if(n < 10){
    return 1;
  }
  int count = 0;
  while(n>0){
    count++;
    n/=10;
  }
  return count;
}
}  // namespace attempt2

/*
💭 First Idea: Divide by 10 until zero, counting the divisions; special-case 0 (Attempt 1: n == 0, Attempt 2: n < 10).
🧩 Key Property / Invariant: Each /10 removes exactly one digit; digits(n) = floor(log10 n) + 1 for n >= 1, and 1 for n = 0.
✅ Key insight: A do-while loop handles n = 0 without a special case.
🔁 Recognition cue for next time: "how many digits" -> repeated /10 (avoid floating log10 for 64-bit values).
⏱  Speed fix for next time: int c = 0; do { ++c; n /= 10; } while (n); return c;  (or std::to_string(n).size()).
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(log n) — Already optimal.
*/
