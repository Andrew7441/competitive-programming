// Codewars — The Office I - Outed
// Topic: math | Tags: average, accumulate
// Complexity (yours): O(n) time, O(1) space

/*
Your colleagues have been looking over your shoulder. When you should have been doing your boring
real job, you've been using the work computers to smash in endless hours of codewars.

In a team meeting, a terrible, awful person declares to the group that you aren't working. You're
in trouble. You quickly have to gauge the feeling in the room to decide whether or not you should
gather your things and leave.

Given an object (meet) containing team member names as keys, and their happiness rating out of 10
as the value, you need to assess the overall happiness rating of the group. If <= 5, return
'Get Out Now!'. Else return 'Nice Work Champ!'.

Happiness rating will be total score / number of people in the room.

Note that your boss is in the room (boss). Their score is worth double its face value (but they
are still just one person!).
*/

#include<numeric>
#include <string>
#include <map>
std::string outed(const std::map<std::string, int> &meet, const std::string &boss){
  return std::accumulate(std::begin(meet), std::end(meet), double (meet.at(boss)),
    [](auto previous, const auto &p){
       return previous + p.second; }) / meet.size() <=5 ? "Get Out Now!" : "Nice Work Champ!";
}

/*
💭 First Idea: accumulate all scores starting from the boss's score (so the boss counts twice), divide by the head count.
🧩 Key Property / Invariant: total = sum of all scores + boss score; people = meet.size().
✅ Key insight: seeding accumulate with the extra boss score handles the "double" without a branch; double init avoids integer division.
🔁 Recognition cue for next time: "weighted average with one special element" -> sum everything, add the extra weight once.
⏱  Speed fix for next time: compare total <= 5 * size in integers to skip floating point entirely.
🛠  Review: correct; O(n) → Already optimal.
*/
