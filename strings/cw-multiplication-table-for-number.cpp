// Codewars — Multiplication table for number
// Topic: strings | Tags: formatting
// Complexity (yours): O(1) time (10 lines)
// From: Codewars/Functions July 2024.md — section "Multiplication table for number"
/*
Kata description:
Your goal is to return the multiplication table for number, which is always an integer from 1 to 10.
For example, number = 5 returns:
1 * 5 = 5
2 * 5 = 10
...
10 * 5 = 50
(lines separated by "\n", no trailing newline).
*/

#include <string>

std::string multi_table(int number)
{
  std::string t;
    for(int i = 1;i<=10;i++){
      int result = i * number;
      t += std::to_string(i) + " * " + std::to_string(number) + " = " + std::to_string(result);
      if(i!=10){
        t +=  "\n";
      }
    }
  return t;
}

/*
💭 First Idea: Loop i = 1..10 appending "i * number = result", newline between lines.
🧩 Key Property / Invariant: No newline after the last line.
✅ Key insight: Add the separator only when i != 10.
🔁 Recognition cue for next time: "join lines with a separator" -> add separator before every item except the first (or after all but the last).
⏱  Speed fix for next time: Nothing to speed up.
🛠  Review: correct; O(1) -> Already optimal.
*/
