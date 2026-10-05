// Codewars — Deodorant Evaporator
// Topic: math | Tags: simulation
// Complexity (yours): O(days) time, O(1) space

/*
This program tests the life of an evaporator containing a gas.

We know the content of the evaporator (content in ml), the percentage of foam or gas lost every day (evap_per_day) and the threshold (threshold) in percentage beyond which the evaporator is no longer useful. All numbers are strictly positive.

The program reports the nth day (as an integer) on which the evaporator will be out of use.

#### Example:
evaporator(10, 10, 5) -> 29
#### Note:

Content is in fact not necessary in the body of the function "evaporator", you can use it or not use it, as you wish. Some people might prefer to reason with content, some other with percentages only. It's up to you but you must keep it as a parameter because the tests have it as an argument.
*/
/*ANSWER:
The program simulates daily gas loss in an evaporator. It calculates the actual threshold amount in milliliters by converting the given percentage threshold. Each day, it reduces the gas content by the given evaporation rate until the content falls below the threshold, then counts the number of days this takes.
*/

#include <iostream>
using namespace std;

class Evaporator
{
  public:
  static int evaporator(double content, double evap_per_day, double threshold){
    int count = 0;
    double threshold_amount = content * (threshold / 100);

    while (content > threshold_amount) {
      content -= content * (evap_per_day / 100);
      count++;
    }

    return count;
  }
};

/*
💭 First Idea: Simulate day by day: content *= (1 − evap%), count days until content ≤ threshold% of start.
🧩 Key Property / Invariant: After d days remaining fraction is (1 − e/100)^d.
✅ Key insight: Closed form exists: d = ceil(log(t/100) / log(1 − e/100)), but the loop is safer against floating-point edge cases.
🔁 Recognition cue for next time: "repeated percentage decay until below X" -> loop or logarithm.
⏱  Speed fix for next time: `content` isn't needed: track a fraction starting at 1.0 and compare with threshold/100.
🛠  Review: correct; O(days) — Already optimal for the kata's sizes.
*/
