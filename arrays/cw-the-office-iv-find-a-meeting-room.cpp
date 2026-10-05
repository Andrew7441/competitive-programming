// Codewars — The Office IV - Find a Meeting Room
// Topic: arrays | Tags: linear-search
// Complexity (yours): O(n) time, O(1) space
// From: Codewars/Functions July 2024.md — section "Function to return index of specific letter in vector"
/*
Kata description:
Your job at the office is to find a meeting room. You get an array of rooms: 'X' is busy, 'O' is empty. Return the index of the first empty room ('O'); if none is available, return -1 in the C++ version ("None available!" in other languages).
*/

#include <algorithm>  // [added: include missing in the note; needed to compile]
#include <vector>

int meeting(const std::vector<char>& rooms) {
  auto it = find(rooms.begin(),rooms.end(), 'O');
  
  if(it != rooms.end()){
    
    int index = it - rooms.begin();
    return index;
  }else{
    return -1;
  }
}

/*
💭 First Idea: std::find for 'O', return the iterator distance or -1.
🧩 Key Property / Invariant: Index = it - begin().
✅ Key insight: First occurrence -> std::find.
🔁 Recognition cue for next time: "index of first X" -> std::find + distance, -1 when end().
⏱  Speed fix for next time: Include <algorithm> explicitly for std::find.
🛠  Review: correct; O(n) -> Already optimal.
*/
