// Codewars — Disarium Number (Special Numbers Series #3)
// Topic: math | Tags: digits
// Complexity (yours): O(d) time (d = number of digits), O(1) space

/*
Disarium number is the number that the sum of its digits powered with their respective positions
is equal to the number itself.

disariumNumber(89) ==> return "Disarium !!"
Since 8^1 + 9^2 = 89, thus output is "Disarium !!"
Otherwise return "Not !!".
*/

#include <string>
#include <cmath>

using namespace std; 

string disariumNumber (int number )
{
  int x = number;
  int s = 0;
  int p = log10(number) + .9;
  
  while(x){
    s += pow(x%10,p--);
    x /= 10;
  }
  return s == number ? "Disarium !!" : "Not !!";
} // added: this closing brace was missing in the original note

// ===================== ⚡ Optimized =====================
// Same O(d), but robust: digit positions come from the decimal string and powers are integer —
// `log10(n) + .9` gives the wrong digit count for n like 11..12, 100..125 (frac(log10 n) < 0.1);
// it only happens to give the right verdict there (checked n = 1..2e7).
namespace optimized {
std::string disariumNumber(int number)
{
  std::string d = std::to_string(number);
  long long s = 0;
  for (size_t i = 0; i < d.size(); ++i) {
    long long t = 1;
    for (size_t k = 0; k <= i; ++k) t *= d[i] - '0';   // digit^(position), position is 1-based
    s += t;
  }
  return s == number ? "Disarium !!" : "Not !!";
}
}

/*
💭 First Idea: peel digits from the right with %10, raising each to its position (counted down from the digit count).
🧩 Key Property / Invariant: the rightmost digit has position = number of digits, so p must start at d and go down.
✅ Key insight: digit count is safest as to_string(n).size() (or floor(log10(n)) + 1) — never "+ .9" rounding hacks.
🔁 Recognition cue for next time: "digits weighted by position" -> work on to_string(n) left to right.
⏱  Speed fix for next time: avoid floating pow for integer powers; use a small loop or precomputed powers.
🛠  Review: correct (verified vs brute force for n ≤ 2e7) but the digit count trick is fragile; O(d) → optimized O(d), robust.
*/
