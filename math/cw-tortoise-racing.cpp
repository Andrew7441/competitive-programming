// Codewars — Tortoise racing
// https://www.codewars.com/kata/55e2adece53b4cdcb900006c
// Topic: math | Tags: time-conversion
// Complexity (yours): O(1) time, O(1) space
// From: Codewars/Functions.md — section "Function to convert speed into seconds and"
/*
Kata description:
Two tortoises A and B race. A has speed v1 feet/hour, B starts later with speed v2 feet/hour and A has a lead of g feet. How long (hours, minutes, seconds, rounded down) until B catches A? Return [h, mn, s], or [-1, -1, -1] if v1 >= v2 (B never catches A).
Example: race(720, 850, 70) -> [0, 32, 18]; race(80, 91, 37) -> [3, 21, 49].
*/

#include <vector>  // [added: include missing in the note; needed to compile]
class Tortoise
{
public:
    static std::vector<int> race(int v1, int v2, int g){
  
    if(v1>=v2){
      return {-1,-1,-1};
    }
		// we want to convert everything to seconds
    int seconds = g * 3600 / (v2-v1); 
    int minutes = seconds / 60;
    int hour = minutes / 60;
					
    return {hour, minutes % 60, seconds % 60}; // both %60 gives the remaining min and h 
    //after removing all of minutes and hours
  }
};
//https://www.codewars.com/kata/55e2adece53b4cdcb900006c/train/cpp

/*
💭 First Idea: Catch-up time = g / (v2 - v1) hours; convert to whole seconds then split into h:m:s.
🧩 Key Property / Invariant: Relative speed is v2 - v1; integer division floors exactly as required.
✅ Key insight: Work in integer seconds to avoid floating rounding errors.
🔁 Recognition cue for next time: "catch up / meeting time" -> distance / relative speed.
⏱  Speed fix for next time: Split seconds with /3600, /60 % 60, % 60.
🛠  Review: correct; O(1) -> Already optimal.
*/
