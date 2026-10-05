// Codewars — Simple consecutive pairs
// https://www.codewars.com/kata/5a3e1319b6486ac96f000049
// Topic: arrays | Tags: implementation
// Complexity (yours): O(n) time, O(1) extra (copies arr by value)
// ⚠️ Review: Attempt 1 reads arr[i+1] past the end for odd-length input (UB); Attempt 2 underflows arr.size() - 1 on an empty vector; see corrected version below.
// Merged: Attempt 1 from Codewars/Functions.md (2024); Attempt 2 from Codewars/2025/February.md
// Import note: <vector> and <cstdlib> were missing in both originals; added (hoisted to the top).

/*
n this Kata your task will be to return the count of pairs that have consecutive numbers as follows:

pairs([1,2,5,8,-4,-3,7,6,5]) = 3
The pairs are selected as follows [(1,2),(5,8),(-4,-3),(7,6),5]
--the first pair is (1,2) and the numbers in the pair are consecutive; Count = 1
--the second pair is (5,8) and are not consecutive
--the third pair is (-4,-3), consecutive. Count = 2
--the fourth pair is (7,6), also consecutive. Count = 3. 
--the last digit has no pair, so we ignore.

*/

#include <vector>
#include <cstdlib>

// ---------- Attempt 1 (Functions, 2024) ----------
int pairs(std::vector<int>arr){
  int count = 0;
  for(size_t i = 0; i < arr.size(); i += 2){
    count += std::abs(arr[i] - arr[i+1]) == 1;
  }
   return count;
}

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
int pairs(std::vector<int>arr){
  int c = 0;
  for(int i = 0; i < arr.size() - 1; i+=2)
    c += std::abs(arr[i] - arr[i+1])==1;

  return c;
}
}  // namespace attempt2

// ===================== ⚡ Optimized =====================
// Fix: loop only while a full pair exists (i + 1 < size), so odd-length input never reads past the end.
namespace optimized {
int pairs(std::vector<int> arr) {
  int count = 0;
  for (size_t i = 0; i + 1 < arr.size(); i += 2)
    count += std::abs(arr[i] - arr[i + 1]) == 1;
  return count;
}
}

/*
💭 First Idea: Step i by 2 and count pairs (arr[i], arr[i+1]) with |difference| == 1.
🧩 Key Property / Invariant: Pairs are fixed (0,1), (2,3), ...; a trailing single element is ignored.
✅ Key insight: The loop condition must guarantee both elements exist: i + 1 < n.
🔁 Recognition cue for next time: "split array into fixed pairs" -> for (i = 0; i + 1 < n; i += 2).
⏱  Speed fix for next time: Write i + 1 < n — `i < n` reads arr[n] on odd n, `i < n - 1` underflows for unsigned n == 0.
🛠  Review: Attempt 1 wrong (odd length reads arr[n], UB — the sample itself has odd length), Attempt 2 correct for non-empty input (empty vector -> underflow UB); O(n) -> fixed O(n).
*/
