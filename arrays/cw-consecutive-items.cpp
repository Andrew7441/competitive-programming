// Codewars — Consecutive items
// Topic: arrays | Tags: implementation, linear-scan
// Complexity (yours): O(n) time, O(1) extra (copies arr by value) (both attempts)
// Merged: Attempt 1 from Codewars/Functions July 2024.md; Attempt 2 from Codewars/2025/February.md
// Import note: <cstddef> (Attempt 1) and <vector> (Attempt 2) were missing in the originals; added (hoisted to the top).

/*
You are given a list of unique integers `arr`, and two integers `a` and `b`. Your task is to find out whether or not `a` and `b` appear consecutively in `arr`, and return a boolean value (`True` if `a` and `b` are consecutive, `False` otherwise).
It is guaranteed that `a` and `b` are both present in `arr`.
*/

#include <cstddef>
#include <vector>

// ---------- Attempt 1 (Functions July 2024) ----------
bool consecutive(std::vector<int> arr, int a, int b) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if ((arr[i] == a && arr[i + 1] == b) || (arr[i] == b && arr[i + 1] == a)) {
            return true;
        }
    }
    return false;
}

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
bool consecutive(std::vector<int>arr, int a,int b){
  for(int i = 0; i < arr.size() - 1; i++){
    if((arr[i] == a && arr[i+1] == b) || (arr[i] == b && arr[i+1] == a)){
      return true;
    }
  }
  return false; 
}
}  // namespace attempt2

// ===================== ⚡ Optimized =====================
// Same scan, but i + 1 < size() cannot underflow (arr.size() - 1 wraps around for an empty vector).
namespace optimized {
bool consecutive(std::vector<int> arr, int a, int b) {
  for (size_t i = 0; i + 1 < arr.size(); ++i)
    if ((arr[i] == a && arr[i + 1] == b) || (arr[i] == b && arr[i + 1] == a))
      return true;
  return false;
}
}

/*
💭 First Idea: Scan adjacent pairs and check for (a,b) or (b,a) (same both times).
🧩 Key Property / Invariant: Values are unique, so a and b are consecutive iff |pos(a) - pos(b)| == 1.
✅ Key insight: One linear scan of neighbouring pairs, both orders.
🔁 Recognition cue for next time: "are two values next to each other" -> adjacent-pair loop or compare indices.
⏱  Speed fix for next time: Prefer i + 1 < n over i < n - 1 with unsigned sizes (underflow on empty; impossible here since a and b are present).
🛠  Review: Attempt 1 correct, Attempt 2 correct (arr guaranteed non-empty); O(n) -> same O(n), underflow-safe version kept below.
*/
