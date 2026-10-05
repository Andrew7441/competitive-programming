// Codewars — Square Every Digit
// Topic: math | Tags: digits, strings
// Complexity (yours): O(d) time, O(d) space

/*
Welcome. In this kata, you are asked to square every digit of a number and concatenate them.

For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1. (81-1-1-81)

Example #2: An input of 765 will/should return 493625 because 72 is 49, 62 is 36, and 52 is 25. (49-36-25)

**Note:** The function accepts an integer and returns an integer.
*/

#include<string>
int square_digits(int num) {
  std::string res ="";
  
  for(auto digit: std::to_string(num)){
    int val = digit - '0';
    res+= std::to_string(val * val);
  }
  return std::stoi(res);
}

// Attempt 2
namespace attempt2 {  // (added wrapper so both attempts compile in one file)

/*
Welcome. In this kata, you are asked to square every digit of a number and concatenate them.

For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1. (81-1-1-81)

Example #2: An input of 765 will/should return 493625 because 72 is 49, 62 is 36, and 52 is 25. (49-36-25)

**Note:** The function accepts an integer and returns an integer.

*/
int square_digits(int num){
  std::string res = "";
  for(auto i: std::to_string(num)){
    int val = i - '0';
    res += std::to_string(val * val);
  }
  
  return std::stoi(res);
  
  
}

}  // namespace attempt2

/*
💭 First Idea: Append to_string(digit²) for each digit, then stoi.
🧩 Key Property / Invariant: Concatenation of the squared digits, read as a number.
✅ Key insight: String concat + stoi is the simplest route.
🔁 Recognition cue for next time: "transform each digit and glue together" -> to_string + per-char work.
⏱  Speed fix for next time: stoi throws if the result exceeds int (e.g. 99999 -> 8181818181); stoll/long long would be safer if the kata allowed it.
🛠  Review: correct (both attempts); O(d) — Already optimal.
*/
