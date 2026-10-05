// Codewars — Small enough? - Beginner
// Topic: arrays | Tags: linear-scan
// Complexity (yours): O(n) time, O(1) extra (but copies arr by value)

/*
You will be given an `array` and a `limit` value. You must check that all values in the array are below or equal to the limit value. If they are, return `true`. Else, return `false`.

You can assume all values in the array are numbers.
*/

#include <vector>

bool small_enough(std::vector<int> arr, int limit) {
  for(int i: arr){
    if(i > limit){
      return false;
    }
  }
  return true;
}

// Attempt 2
namespace attempt2 {  // (added wrapper so both attempts compile in one file)
/*
You will be given an `array` and a `limit` value. You must check that all values in the array are below or equal to the limit value. If they are, return `true`. Else, return `false`.

You can assume all values in the array are numbers.
*/
#include <vector>

bool small_enough(std::vector<int> arr, int limit) {
  for(unsigned long i = 0; i < arr.size();i++){
    if(arr[i] > limit){
      return false;
    }
  }
  return true;
}

}  // namespace attempt2

/*
💭 First Idea: Return false on the first element > limit, else true.
🧩 Key Property / Invariant: All ≤ limit ⇔ max ≤ limit.
✅ Key insight: Early exit on the first violation.
🔁 Recognition cue for next time: "do all elements satisfy P?" -> std::all_of.
⏱  Speed fix for next time: return std::all_of(arr.begin(), arr.end(), [&](int x){ return x <= limit; });
🛠  Review: correct (both attempts); O(n) — Already optimal.
*/
