// Codewars — Nth Smallest Element (Array Series #4)
// https://www.codewars.com/kata/5a512f6a80eba857280000fc
// Topic: sorting | Tags: arrays, selection
// Complexity (yours): O(n log n) time, O(n) space (vector passed by value)

/*
March 5 — program to return the Nth smallest element in a vector.
Given an array/list of integers, find the Nth smallest element in this array of integers.
- Array/list size is at least 3; numbers can be positive, negative or zero.
- Repetition can occur, so don't remove duplicates.
nthSmallest({3,1,2}, 2) -> 2;  nthSmallest({15,20,7,10,4,3}, 3) -> 7;  nthSmallest({2,169,13,-5,0,-1}, 4) -> 2
*/

#include <vector>
#include <algorithm> // added: std::sort (missing in the original note)
using namespace std;
//March 5
// program to return the Nth smallest digit in a v
int nthSmallest (vector<int> passed , int n)
{
  std::sort(passed.begin(), passed.end());
  return passed[n-1];
}

// ===================== ⚡ Optimized =====================
// O(n) average instead of O(n log n): std::nth_element only partially orders the array (quickselect).
namespace optimized {
int nthSmallest (vector<int> passed , int n)
{
  std::nth_element(passed.begin(), passed.begin() + (n - 1), passed.end());
  return passed[n - 1];
}
}

/*
💭 First Idea: sort the copy, return element n-1.
🧩 Key Property / Invariant: the n-th smallest (with duplicates) is index n-1 of the sorted array.
✅ Key insight: you only need ONE position correct -> selection (nth_element / quickselect), not a full sort.
🔁 Recognition cue for next time: "k-th smallest/largest" -> nth_element (or a size-k heap when streaming).
⏱  Speed fix for next time: nth_element(v.begin(), v.begin() + k - 1, v.end()).
🛠  Review: correct; yours O(n log n) → optimized O(n) average.
*/
