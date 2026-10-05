// Codewars — A Needle in the Haystack
// Topic: arrays | Tags: linear-search
// Complexity (yours): O(n) time, O(1) space
// From: Codewars/Functions.md — section "Function to return a specific word"
/*
Kata description:
Given a vector of strings, find the position of "needle" and return "found the needle at position <index>". The needle is guaranteed to be present.
*/

#include <vector>
#include <string>

std::string findNeedle(const std::vector<std::string>& haystack)
{
  for(int i = 0; i < haystack.size(); i++){
    if(haystack[i] == "needle"){
      return "found the needle at position " + std::to_string(i);
    }
  }
}

/*
💭 First Idea: Linear scan comparing each element with "needle".
🧩 Key Property / Invariant: The needle always exists, so the loop always returns.
✅ Key insight: Linear search is the best possible on an unsorted array.
🔁 Recognition cue for next time: "find position of X in a list" -> linear scan or std::find.
⏱  Speed fix for next time: Add a fallback return after the loop to silence -Wreturn-type.
🛠  Review: correct (falls off the end without return if not found, but the kata guarantees it); O(n) -> Already optimal.
*/
