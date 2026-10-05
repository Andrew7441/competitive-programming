// Codewars — Minimize Sum Of Array (Array Series #1)
// Topic: greedy | Tags: sorting, two-pointers
// Complexity (yours): O(n log n) time, O(1) extra space

//feb 3
/*
**_Given_** an **_array of integers_** , **_Find the minimum sum_** which is obtained _from summing each Two integers product_ .
# Notes

- **_Array/list_** _will contain_ **_positives only_** .
- **_Array/list_** _will always have_ **_even size_**
minSum({5,4,2,3}) ==> return (22)
5*2 + 3*4 = 22

*/
#include <vector>
#include <algorithm>

using namespace std;

int minSum (vector<int>passed)
{
  int n = passed.size(); 
  sort(passed.begin(), passed.end());
  int sum = 0;
  
  for(int i = 0; i < n / 2; i++){ // divide size by half because i want 
    sum += passed[i] * passed[n - i - 1];
  }
  return sum; 
}

/*
💭 First Idea: Sort, then pair the smallest with the largest moving inward.
🧩 Key Property / Invariant: Rearrangement inequality: pairing opposite ends minimises the sum of products.
✅ Key insight: Smallest×largest, 2nd smallest×2nd largest, … gives the minimum.
🔁 Recognition cue for next time: "minimise sum of pairwise products" -> sort + pair ends.
⏱  Speed fix for next time: Use long long for the sum if values can be large.
🛠  Review: correct; O(n log n) — Already optimal.
*/
