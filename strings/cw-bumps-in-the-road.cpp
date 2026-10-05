// Codewars — Bumps in the Road
// Topic: strings | Tags: counting
// Complexity (yours): O(n) time, O(1) space

/*
April 27, 2025
Your car is old, it breaks easily. The shock absorbers are gone and you think it can handle about 15 more bumps before it dies totally.

Unfortunately for you, your drive is very bumpy! Given a string showing either flat road (`_`) or bumps (`n`). If you are able to reach home safely by encountering `15 bumps or less`, return `Woohoo!`, otherwise return `Car Dead`
*/
#include <string>
#include <algorithm>

std::string bumps(std::string road){
  int count = 0;
  int length = road.length();
  
  for(int i = 0; i < length;i++){
    if(road[i] == 'n'){
      count++;
    }
  }
  if(count <= 15){
    return "Woohoo!";
  }else{
    return "Car Dead";
  }
} // NOTE (reorg): closing brace of bumps() was missing in the original paste; added so the file compiles.
//BEST PRACTICE:

namespace best_practice {  // (added wrapper: same signature as yours, would be a redefinition)
std::string bumps(std::string road){

	return std::count(road.begin(), road.end(), 'n') >15 ? "Car Dead" : "Woohoo!";
	
}
}  // namespace best_practice

/*
💭 First Idea: Count 'n' characters, compare with 15.
🧩 Key Property / Invariant: Car survives iff #bumps ≤ 15.
✅ Key insight: std::count(road.begin(), road.end(), 'n') does the counting in one call.
🔁 Recognition cue for next time: "count one character" -> std::count.
⏱  Speed fix for next time: Use the std::count one-liner (the best-practice version already in the file).
🛠  Review: correct (logic; paste lost the closing brace); O(n) — Already optimal.
*/
