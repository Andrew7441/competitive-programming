// Codewars — Sum of two lowest positive integers
// Topic: sorting | Tags: arrays
// Complexity (yours): O(n log n) time, O(n) space (vector passed by value)

/*
Create a function that returns the sum of the two lowest positive numbers given an array of
minimum 4 positive integers. No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.
[10, 343445353, 3453445, 3453545353453] should return 3453455.
*/

#include <vector>
#include <algorithm> // added: std::sort needs it (missing in the original note)

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
  std::sort(numbers.begin(),numbers.end());
  auto sum = numbers.at(0) + numbers.at(1);
  return sum;
}

// ===================== ⚡ Optimized =====================
// O(n) instead of O(n log n): one pass keeping the two smallest; sum in long long so two big ints can't overflow.
namespace optimized {
long sumTwoSmallestNumbers(std::vector<int> numbers)
{
  long long a = numbers[0], b = numbers[1];          // a <= b
  if (a > b) std::swap(a, b);
  for (size_t i = 2; i < numbers.size(); ++i) {
    long long x = numbers[i];
    if (x < a) { b = a; a = x; }
    else if (x < b) b = x;
  }
  return (long)(a + b);
}
}

/*
💭 First Idea: sort the array and add the first two elements.
🧩 Key Property / Invariant: only the two smallest values matter; the order of the rest does not.
✅ Key insight: "k smallest" for tiny k = a single pass with k running minima (or std::partial_sort / nth_element).
🔁 Recognition cue for next time: "two lowest / two largest" -> track two variables in one loop.
⏱  Speed fix for next time: `auto sum = int + int` is still int — widen to long long BEFORE adding.
🛠  Review: correct (int+int could overflow for values near INT_MAX); yours O(n log n) → optimized O(n).
*/
