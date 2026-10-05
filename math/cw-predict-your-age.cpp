// Codewars — Predict your age!
// Topic: math | Tags: sqrt
// Complexity (yours): O(1) time, O(1) space

/*
- Take a list of ages when each of your great-grandparent died.
- Multiply each number by itself.
- Add them all together.
- Take the square root of the result.
- Divide by two.
(Return the result truncated to an int.)
*/

#include <math.h>
int predictAge(int age1, int age2, int age3, int age4, int age5, int age6, int age7, int age8)
{
  int res;
  int a1= age1 * age1;
  int a2= age2 * age2;
  int a3= age3 * age3;
  int a4= age4 * age4;
  int a5= age5 * age5;
  int a6= age6 * age6;
  int a7= age7 * age7;
  int a8= age8 * age8;
  res = a1 + a2 + a3 + a4 + a5 + a6 +a7 + a8;
  res = sqrt(res);
  res /= 2;
 
  return res;
}
//OR

// #include <math.h>
// int predictAge(int age1, int age2, int age3, int age4, int age5, int age6, int age7, int age8)
// {
//   int a[8] = { age1,  age2,  age3,  age4,  age5,  age6,  age7,  age8};
//   int r = 0;
//   for(int i = 0; i< 8; i++){
//     a[i] *= a[i];
//     r += a[i];
//   }
  
//   return sqrt(r)/2;
// }

//OR

//return sqrt(a1*a1+a2*a2+a3*a3+a4*a4+a5*a5+a6*a6+a7*a7+a8*a8)/2;

/*
💭 First Idea: square each age, sum, sqrt, divide by 2 (with int truncation).
🧩 Key Property / Invariant: floor(floor(x) / 2) == floor(x / 2), so truncating sqrt first is safe.
✅ Key insight: it is the Euclidean norm of the 8 ages, halved — std::hypot-style formula.
🔁 Recognition cue for next time: "square, add, sqrt" -> norm; use an array + loop instead of 8 variables.
⏱  Speed fix for next time: the one-liner `return sqrt(age1*age1 + ... + age8*age8) / 2;` (the last //OR uses a1..a8 — use age1..age8).
🛠  Review: correct; O(1) → Already optimal.
*/
