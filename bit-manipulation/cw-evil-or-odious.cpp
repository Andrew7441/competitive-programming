// Codewars — Evil or Odious
// Topic: bit-manipulation | Tags: popcount, parity
// Complexity (yours): O(log n) time, O(1) space

/*
The number n is Evil if it has an even number of 1's in its binary representation.
The first few Evil numbers: 3, 5, 6, 9, 10, 12, 15, 17, 18, 20

The number n is Odious if it has an odd number of 1's in its binary representation.
The first few Odious numbers: 1, 2, 4, 7, 8, 11, 13, 14, 16, 19

Return "It's Evil!" or "It's Odious!".
*/

#include <string> // added: std::string (missing in the original note)

std::string evil(int n)
{
  int count = 0;
  
  while(n>0){
    if(n % 2){
      count++;
    }
    n/=2;
  }
  return ((count % 2) == 0 ? "It's Evil!" : "It's Odious!");
}

/*
💭 First Idea: count the 1-bits with repeated %2 and /2, then check parity.
🧩 Key Property / Invariant: n % 2 is the lowest bit; n /= 2 shifts it out.
✅ Key insight: this is just popcount parity — __builtin_popcount(n) & 1 (or __builtin_parity(n)).
🔁 Recognition cue for next time: "number of 1's in binary" -> popcount builtin / bitset<32>(n).count().
⏱  Speed fix for next time: return __builtin_parity(n) ? "It's Odious!" : "It's Evil!";
🛠  Review: correct; O(log n) → Already optimal (builtin is just shorter).
*/
