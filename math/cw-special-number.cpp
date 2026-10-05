// Codewars — Special Number (Special Numbers Series #5)
// Topic: math | Tags: digits, strings
// Complexity (yours): O(d) time, O(d) space, d = number of digits (both attempts)
// Merged: Attempt 1 from Codewars/Functions July 2024.md; Attempt 2 from Codewars/2025/February.md

/*
A number is a **Special Number** if its digits only consists of 0, 1, 2, 3, 4 or 5
Given a number, determine if it is a special number or not.
Return "Special!!" if it is special, otherwise "NOT!!".
Examples: 2 -> "Special!!", 9 -> "NOT!!", 23 -> "Special!!", 39 -> "NOT!!", 59 -> "NOT!!", 513 -> "Special!!", 709 -> "NOT!!".
*/

#include <string>

// ---------- Attempt 1 (Functions July 2024) ----------
  using namespace std; 

  string specialNumber (int n)
  {
    string num = to_string(n); //convert n to string to work with it
    
    for(auto digit : num){ // iterate over each number
      if(digit < '0' or digit > '5'){ // check if its not within the range
        return "NOT!!"; // return if true
      }
  }

    return "Special!!"; // if if-statement is false
  }

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
using namespace std; 

string specialNumber (int number)
{
  string num = std::to_string(number);
  
  for(auto i: num){
    if(i < '0' or i > '5'){
      return "NOT!!";
    }
  }
  return "Special!!";
}
}  // namespace attempt2

/*
💭 First Idea: to_string(n) and check every digit char is in '0'..'5', early return "NOT!!" (same both times).
🧩 Key Property / Invariant: A number is special iff each of its digits <= 5; one bad digit is enough to answer NOT!!.
✅ Key insight: Early exit on the first digit > 5; a % 10 loop avoids the string.
🔁 Recognition cue for next time: "property of every digit" -> loop over digits with early exit (or std::all_of).
⏱  Speed fix for next time: Digits of a positive int are never < '0', so only check > '5'; while (n) { if (n % 10 > 5) return "NOT!!"; n /= 10; }
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(d) — Already optimal.
*/
