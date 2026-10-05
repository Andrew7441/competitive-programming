// Codewars — Sort and Star
// Topic: strings | Tags: sorting
// Complexity (yours): O(n log n · L) time for the sort + O(L^2) for the inserts, O(n·L) space

/*
You will be given a list of strings. You must sort it alphabetically (case-sensitive, and based
on the ASCII values of the chars) and then return the first value.

The returned value must be a string, and have "***" between each of its letters.
*/

#include <vector>
#include <string>
#include <algorithm>

std::string twoSort(std::vector<std::string> s)
{
  sort(s.begin(),s.end());
  std::string res = s.at(0);
  for(int i = 1; i < res.size();i+=4){
    res.insert(i, "***");
  }
  return res;
}

// ===================== ⚡ Optimized =====================
// O(n·L) instead of O(n log n · L): only the smallest string is needed, so use min_element; build the result once (no repeated inserts).
namespace optimized {
std::string twoSort(std::vector<std::string> s)
{
  const std::string& first = *std::min_element(s.begin(), s.end());
  std::string res;
  for (size_t i = 0; i < first.size(); ++i) {
    if (i) res += "***";
    res += first[i];
  }
  return res;
}
}

/*
💭 First Idea: sort the whole list, take s[0], and insert "***" after every letter (step 4 because the string grows).
🧩 Key Property / Invariant: after inserting at i, the next original letter sits at i + 4.
✅ Key insight: "first after sorting" == minimum — no need to sort everything.
🔁 Recognition cue for next time: "sort then take the first/last" -> min_element / max_element.
⏱  Speed fix for next time: build the answer with += instead of insert() in a loop (each insert shifts the tail).
🛠  Review: correct; yours O(n log n · L) → optimized O(n · L).
*/
