// Codewars — Cat and Mouse - Easy Version
// Topic: strings | Tags: implementation
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions July 2024.md — section "Cat and Mouse - Easy Version"
/*
Kata description:
You will be given a string (x) featuring a cat 'C' and a mouse 'm'. The rest of the string will be made up of '.'.
You need to find out if the cat can catch the mouse from its current position. The cat can jump over three characters. So:
C.....m returns 'Escaped!' <-- more than three characters between
C...m returns 'Caught!' <-- as there are three characters between the two, the cat can jump.
*/

#include <string>

std::string cat_mouse(std::string x) {
  return x.size() <= 5 ? "Caught!" : "Escaped!";
}

// ===================== ⚡ Optimized =====================
// Measures the actual gap between 'C' and 'm', so it also works if they are not at the two ends of the string.
namespace optimized {
std::string cat_mouse(std::string x) {
  long gap = std::labs((long)x.find('C') - (long)x.find('m')) - 1;
  return gap <= 3 ? "Caught!" : "Escaped!";
}
}

/*
💭 First Idea: String length <= 5 means at most 3 dots between C and m.
🧩 Key Property / Invariant: With C and m at the ends, gap = size - 2.
✅ Key insight: Gap = |pos(C) - pos(m)| - 1; caught iff gap <= 3.
🔁 Recognition cue for next time: "distance between two markers in a string" -> find both and subtract.
⏱  Speed fix for next time: Do not rely on the layout; compute positions explicitly.
🛠  Review: correct (relies on C and m being at the ends, true in this kata); O(1) -> O(n) robust version.
*/
