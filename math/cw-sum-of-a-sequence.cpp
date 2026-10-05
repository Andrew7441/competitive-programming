// Codewars — Sum of a sequence
// Topic: math | Tags: arithmetic-series
// Complexity (yours): O((end - start) / step) time, O(1) space

/*Mar 8
Your task is to write a function which returns the sum of a sequence of integers.
The sequence is defined by 3 non-negative values: **begin**, **end**, **step**.
If **begin** value is greater than the **end**, your function should return **0**. If **end** is not the result of an integer number of steps, then don't add it to the sum. See the 4th example below.
**Examples**
2,2,2 --> 2
2,6,2 --> 12 (2 + 4 + 6)
1,5,1 --> 15 (1 + 2 + 3 + 4 + 5)
1,5,3  --> 5 (1 + 4)
*/
int sequenceSum(int start, int end, int step)
{
  if(start>end)
    return 0;
  
  int sum = 0;
  
  for(int i = start; i <= end; i+=step){
    sum += i;
  }
  
  return sum;


}

// ===================== ⚡ Optimized =====================
// O(1) instead of O(count): arithmetic series — k = (end - start) / step + 1 terms, sum = k·start + step·k(k-1)/2.
namespace optimized {
int sequenceSum(int start, int end, int step)
{
  if (start > end) return 0;
  long long k = (long long)(end - start) / step + 1;
  return (int)(k * start + (long long)step * k * (k - 1) / 2);
}
}

/*
💭 First Idea: loop from start to end in steps of step and add each term.
🧩 Key Property / Invariant: the terms are start + i·step for i = 0..k-1 with k = floor((end-start)/step) + 1.
✅ Key insight: sum of an arithmetic progression = k·first + step·k(k-1)/2 — no loop needed.
🔁 Recognition cue for next time: "sum of start, start+step, ... up to end" -> arithmetic series formula.
⏱  Speed fix for next time: guard step == 0 (the loop would never end) and use long long for the sum.
🛠  Review: correct; yours O(count) → optimized O(1).
*/
