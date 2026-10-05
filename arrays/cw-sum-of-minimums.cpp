// Codewars — Sum of Minimums!
// Topic: arrays | Tags: matrix
// Complexity (yours): O(m·n) time, O(n) extra (row copy)
// NOTE (reorg): added <algorithm> — missing in the original and needed to compile outside Codewars.
#include <algorithm>

/* FEB 9
Given a 2D ( nested ) list ( array, vector, .. ) of size `m * n`, your task is to find the sum of the minimum values in each row.
For Example:

[ [ 1, 2, 3, 4, 5 ]        #  minimum value of row is 1
, [ 5, 6, 7, 8, 9 ]        #  minimum value of row is 5
, [ 20, 21, 34, 56, 100 ]  #  minimum value of row is 20
]
So the function should return `26` because the sum of the minimums is `1 + 5 + 20 = 26`.
Note: You will always be given a non-empty list containing positive values.
*/


#include <vector>

int sum_of_minimums(const std::vector<std::vector<int>> &numbers)
{
  int sum = 0;
  
  for(auto i: numbers){
    sum += *(std::min_element(i.begin(), i.end()));
  }
  
  return sum;
}


/*
💭 First Idea: For each row add *min_element(row).
🧩 Key Property / Invariant: Answer = Σ over rows of min(row).
✅ Key insight: Every element must be seen once; nothing better than O(m·n).
🔁 Recognition cue for next time: "per-row aggregate then total" -> loop rows + std algorithm.
⏱  Speed fix for next time: Use `const auto& i` — `auto i` copies every row.
🛠  Review: correct; O(m·n) — Already optimal.
*/
