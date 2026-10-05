// Codewars — Find the odd int
// Topic: bit-manipulation | Tags: hashing, brute-force
// Complexity (yours): O(n²) time, O(1) space
// NOTE (reorg): added <algorithm> — missing in the original and needed to compile outside Codewars.
#include <algorithm>

/*
Given an array of integers, find the one that appears an odd number of times.

There will always be only one integer that appears an odd number of times.

### Examples

`[7]` should return `7`, because it occurs 1 time (which is odd).  
`[0]` should return `0`, because it occurs 1 time (which is odd).  
`[1,1,2]` should return `2`, because it occurs 1 time (which is odd).  
`[0,1,0,1,0]` should return `0`, because it occurs 3 times (which is odd).  
`[1,2,2,3,3,3,4,3,3,3,2,2,1]` should return `4`, because it appears 1 time (which is odd).
*/
#include <vector>

int findOdd(const std::vector<int>& numbers){
  if(numbers.size()==1){
    return numbers[0];
  }
  for(int i = 0; i< numbers.size();i++){
    int count = 0;
    for(int j = 0; j < numbers.size();j++){
      if(numbers[i] == numbers[j]){
        count++;
      }
    }
    if(count % 2 != 0)
    return numbers[i];
  
  }
} // NOTE (reorg): closing brace of findOdd was missing in the original paste; added so the file compiles.
//BEST PRACTICE:
#include <vector>
namespace best_practice {  // (added wrapper: same signature as yours, would be a redefinition)

int findOdd(const std::vector<int>& numbers){
  for (auto elem: numbers){
    if (std::count(numbers.begin(), numbers.end(), elem) % 2 != 0) {
      return elem;
    }
  }
  return 0;
}
}  // namespace best_practice

// ===================== ⚡ Optimized =====================
// O(n) instead of O(n^2): equal values cancel under XOR, only the odd-count one survives.
namespace optimized {
int findOdd(const std::vector<int>& numbers) {
  int r = 0;
  for (int x : numbers) r ^= x;
  return r;
}
}

/*
💭 First Idea: For each element count its occurrences with a nested loop; return the first with an odd count.
🧩 Key Property / Invariant: x ^ x = 0 and x ^ 0 = x, so XOR of all elements leaves exactly the odd-count value.
✅ Key insight: XOR everything: pairs cancel, the odd one survives — O(n) time, O(1) space.
🔁 Recognition cue for next time: "exactly one value appears an odd number of times" -> XOR fold.
⏱  Speed fix for next time: Replace the double loop with `int r = 0; for (int x : numbers) r ^= x; return r;`
🛠  Review: correct logic but O(n²) (and the paste lost its closing brace / final return) → optimized O(n) XOR.
*/
