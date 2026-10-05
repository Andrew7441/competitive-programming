// Codewars — Are they the "same"?
// Topic: sorting | Tags: arrays, hashing
// Complexity (yours): O(n log n) time, O(n) space

/*
Given two arrays `a` and `b` write a function `comp(a, b)` (or `compSame(a, b)`) that checks
whether the two arrays have the "same" elements, with the same multiplicities (the multiplicity
of a member is the number of times it appears). "Same" means, here, that the elements in `b` are
the elements in `a` squared, regardless of the order.

Valid arrays
a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]

comp(a, b) returns true because in `b` 121 is the square of 11, 14641 is the square of 121,
20736 the square of 144, 361 the square of 19, 25921 the square of 161, and so on. It gets
obvious if we write `b`'s elements in terms of squares:

a = [121, 144, 19, 161, 19, 144, 19, 11] 
b = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]

Invalid arrays
If, for example, we change the first number to something else, comp is not returning true anymore:

a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [132, 14641, 20736, 361, 25921, 361, 20736, 361]
comp(a,b) returns false because in `b` 132 is not the square of any number of `a`.

a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [121, 14641, 20736, 36100, 25921, 361, 20736, 361]
comp(a,b) returns false because in `b` 36100 is not the square of any number of `a`.

Remarks
- `a` or `b` might be [] or {} (all languages except R, Shell).
- `a` or `b` might be nil/null/None (not in C++). If so, the problem doesn't make sense so return false.
*/

// Attempt 1 (September 2024)
#include <vector>
#include <algorithm> // added: std::sort (missing in the original note)
class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b) {
      if(a.size() != b.size()){
        return false;
      }
      std::vector<int> squared;
      for(int i: a){
        squared.push_back(i*i);
      }
      std::vector<int> bsorted = b;
      std::sort(bsorted.begin(),bsorted.end());
      std::sort(squared.begin(),squared.end());
      
      return bsorted == squared;
      }
};

// Attempt 2 (March 9, 2025)
#include <vector>
#include <bits/stdc++.h>

namespace attempt2 {
class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b){
      
      if(a.size() != b.size()){
        return 0;
      }
      
      std::vector<int> squared;
      
      for(auto i: a){
        squared.push_back(i*i);
      }
      
      std::vector<int> bsorted = b;
      std::sort(bsorted.begin(),bsorted.end());
      std::sort(squared.begin(),squared.end());
      
      return squared == bsorted;
    }
};
} // namespace attempt2
//Best practice

#include <algorithm>

namespace best_practice {
class Same {
public:
  static bool comp(std::vector<int>, std::vector<int>);
};

bool Same::comp(std::vector<int> a, std::vector<int> b) {
  for (auto& v : a) {
    v = v * v;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return a == b;
}
} // namespace best_practice

/*
💭 First Idea: square every element of a, sort both arrays, compare them as multisets.
🧩 Key Property / Invariant: two arrays are equal as multisets iff their sorted versions are equal.
✅ Key insight: "same elements with multiplicities, any order" = sort + == (or a frequency map for O(n)).
🔁 Recognition cue for next time: "same elements regardless of order" -> sort both, or count with unordered_map.
⏱  Speed fix for next time: take by value and modify in place (like best practice) — no extra copies; the size check is implied by ==.
🛠  Review: correct (both attempts); O(n log n) → Already optimal in practice (hash-count gives O(n) expected).
*/
