// Codewars — Drone Fly-By
// Topic: strings | Tags: implementation
// Complexity (yours): O(m) time where m = drone.size(), O(1) extra space (both attempts)
// Merged: Attempt 1 from Codewars/Functions July 2024.md; Attempt 2 from Codewars/2025/February.md

/*
The other day I saw an amazing video where a guy hacked some wifi controlled lightbulbs by flying a drone past them. Brilliant.

In this kata we will recreate that stunt... sort of.

You will be given two strings: `lamps` and `drone`. `lamps` represents a row of lamps, currently off, each represented by `x`. When these lamps are on, they should be represented by `o`.

The `drone` string represents the position of the drone `T` (any better suggestion for character??) and its flight path up until this point `=`. The drone always flies left to right, and always begins at the start of the row of lamps. Anywhere the drone has flown, including its current position, will result in the lamp at that position switching on.
Return the resulting lamps string, e.g. lamps "xxxxxx", drone "==T" -> "oooxxx".
*/

#include <string>
#include <bits/stdc++.h>

// ---------- Attempt 1 (Functions July 2024) ----------
std::string flyBy(std::string lamp, std::string drone){
  for(int i = 0; i<drone.length(); i++){
    lamp[i] = 'o';
  }
  return lamp;
}

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::string flyBy(std::string lamp, std::string drone){
  
  for(int i = 0; i < drone.size(); i++){
    lamp[i] = 'o';
  }
  
  return lamp;
}
}  // namespace attempt2

/*
💭 First Idea: Turn on the first drone.size() lamps (same both times).
🧩 Key Property / Invariant: The drone path (including T) is always a prefix of the lamp row.
✅ Key insight: Only the drone string's length matters, not its characters.
🔁 Recognition cue for next time: "prefix of length k gets changed" -> std::fill_n / replace the first k.
⏱  Speed fix for next time: std::fill_n(lamp.begin(), std::min(lamp.size(), drone.size()), 'o'); also guards a drone longer than lamps.
🛠  Review: Attempt 1 correct, Attempt 2 correct (kata guarantees drone <= lamps); O(m) — Already optimal.
*/
