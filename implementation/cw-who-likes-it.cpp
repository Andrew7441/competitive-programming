// Codewars — Who likes it?
// https://www.codewars.com/kata/5266876b8f4bf2da9b000362
// Topic: implementation | Tags: strings, formatting, case-work
// Complexity (yours): O(1) cases (plus output length) (all attempts)
// Merged: Attempt 1 from Codewars/Functions 2.md (2024); Attempt 2 from Codewars/2025/February.md; Attempt 3 from Codewars/2025/May.md

/*
You probably know the "like" system from Facebook and other pages. People can "like" blog posts, pictures or other items. We want to create the text that should be displayed next to such an item.

Implement the function which takes an array containing the names of people that like an item. It must return the display text as shown in the examples:

[]                                -->  "no one likes this"
["Peter"]                         -->  "Peter likes this"
["Jacob", "Alex"]                 -->  "Jacob and Alex like this"
["Max", "John", "Mark"]           -->  "Max, John and Mark like this"
["Alex", "Jacob", "Mark", "Max"]  -->  "Alex, Jacob and 2 others like this"
Note: For 4 or more names, the number in `"and 2 others"` simply increases.
*/

#include <string>
#include <vector>

// ---------- Attempt 1 (Functions 2, 2024) ----------
std::string likes(const std::vector<std::string> &names)
{
    size_t num_likes = names.size();

    if (num_likes == 0) {
        return "no one likes this";
    } else if (num_likes == 1) {
        return names[0] + " likes this";
    } else if (num_likes == 2) {
        return names[0] + " and " + names[1] + " like this";
    } else if (num_likes == 3) {
        return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    } else {
        return names[0] + ", " + names[1] + " and " + std::to_string(num_likes - 2) + " others like this";
    }
}

// ---------- Attempt 2 (February 2025) ----------
//Feb 8
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::string likes(const std::vector<std::string> &names)
{
  size_t numsize = names.size();
  
  if(numsize == 0){
    return "no one likes this";
  }else if(numsize == 1){
    return names[0] + " likes this";
  }else if(numsize == 2){
    return names[0] + " and " + names[1] + " like this";
  }else if(numsize == 3){
    return names[0] + ", " + names[1] + " and " + names[2] + " like this";
  }else if(numsize >= 4){
    return names[0] + ", " + names[1] + " and " + std::to_string(numsize - 2) + " others like this";
  }
}
}  // namespace attempt2

// ---------- Attempt 3 (May 2025) ----------
// May 6
namespace attempt3 {  // (wrapper added in merge so all attempts compile in one file)
std::string likes(const std::vector<std::string> &names)
{
    if(names.empty()){
      return "no one likes this";
    }else if(names.size()==1){
      return names.at(0) + " likes this";
    }else if(names.size()==2){
      return names.at(0) + " and " + names.at(1) + " like this";
    }else if(names.size()==3){
      return names.at(0) + ", " + names.at(1) + " and " + names.at(2) + " like this";
    }else if(names.size()>=4){
      return names.at(0) + ", " + names.at(1) + " and " + std::to_string(names.size()-2)  + " others like this";
    }
}
}  // namespace attempt3

/*
💭 First Idea: if/else chain on the number of names: 0, 1, 2, 3, 4+ (all three attempts).
🧩 Key Property / Invariant: For 4+ names only the first two are shown, plus (n - 2) others.
✅ Key insight: Pure case analysis on the size.
🔁 Recognition cue for next time: "display text depends on count buckets" -> switch on min(size, 4) with a default for "many".
⏱  Speed fix for next time: End with a plain `else` like Attempt 1 — Attempts 2-3 end in `else if (>= 4)`, so g++ warns 'control reaches end of non-void function'.
🛠  Review: Attempt 1 correct, Attempt 2 correct, Attempt 3 correct; O(1) — Already optimal.
*/
