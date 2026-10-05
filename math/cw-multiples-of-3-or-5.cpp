// Codewars — Multiples of 3 or 5
// Topic: math | Tags: inclusion-exclusion
// Complexity (yours): O(n) time, O(1) space

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number
passed in.

Additionally, if the number is negative, return 0.

Note: If the number is a multiple of both 3 and 5, only count it once.
*/

int solution(int number) 
{
  int res=0;
  if(number<0){
    return 0;
  }
  
  for(int i=0;i<number;i++){
    if(i % 3 == 0 or i % 5 ==0 or i % 3 == 0 and i % 5){
      res += i;
    }
  }
  return res;
}

// ===================== ⚡ Optimized =====================
// O(1) instead of O(n): inclusion–exclusion with arithmetic series: S(3) + S(5) - S(15).
namespace optimized {
int solution(int number)
{
  if (number <= 0) return 0;
  auto S = [&](long long k) {          // sum of multiples of k strictly below number
    long long m = (number - 1) / k;
    return k * m * (m + 1) / 2;
  };
  return (int)(S(3) + S(5) - S(15));
}
}

/*
💭 First Idea: loop below number and add i if divisible by 3 or 5.
🧩 Key Property / Invariant: `i % 3 == 0 or i % 5 == 0` already counts multiples of 15 once — the third clause is redundant.
✅ Key insight: sum of multiples of k below n = k · m(m+1)/2 with m = (n-1)/k; subtract multiples of 15 (counted twice).
🔁 Recognition cue for next time: "sum of multiples of a OR b below n" -> inclusion–exclusion + arithmetic series.
⏱  Speed fix for next time: write the O(1) formula directly; use long long inside (k·m² overflows int for large n).
🛠  Review: correct; yours O(n) → optimized O(1).
*/
