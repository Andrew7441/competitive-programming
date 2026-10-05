// Codewars — Filter the number
// Topic: strings | Tags: parsing
// Complexity (yours): O(n) time, O(1) space (both attempts)
// Merged: Attempt 1 from Codewars/Functions.md (2024); Attempt 2 from Codewars/2025/February.md

/*
given a string of numbers and letters mixed up, you have to return all the numbers in that string in the order they occur.
Describe(sample_test)
{
    It(example_tests)
    {
        do_test("123", 123);
        do_test("a1b2c3", 123);
        do_test("aa1bb2cc3dd", 123);
    }
};
*/

#include <string>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

// ---------- Attempt 1 (Functions, 2024) ----------
long long filter_string(const std::string &value)
{
  long long res=0; 
  for(char i: value){
    if(std::isdigit(i)){
      res = res*10 + (i - '0');
    }
  }
  return res;
}

// ---------- Attempt 2 (February 2025) ----------
//feb 5
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
long long filter_string(const std::string &value)
{
  long long res=0; 
  for(char i: value){
    if(std::isdigit(i)){
      res = res*10 + (i - '0');
    }
  }
  return res;
}
}  // namespace attempt2

/*
💭 First Idea: Scan characters; for each digit do res = res*10 + digit (identical code both times).
🧩 Key Property / Invariant: Building the number left to right = Horner's rule in base 10.
✅ Key insight: No need to build an intermediate string and call stoll.
🔁 Recognition cue for next time: "extract a number from noisy text" -> isdigit + res*10 + d.
⏱  Speed fix for next time: Cast to unsigned char before std::isdigit to avoid UB on negative chars.
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(n) — Already optimal.
*/
