// Codewars — Directions Reduction
// Topic: stack | Tags: strings, simulation
// Complexity (yours): O(n^2) time (erase + restart from the beginning), O(1) extra space

/*
Write a function dirReduc which will take an array of strings and returns an array of strings with
the needless directions removed (W<->E or S<->N side by side).
e.g. {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"} -> {"WEST"}
*/

#include <vector>
#include <string> // added: std::string (missing in the original note)
class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr){
      
      for(int i = 1; i< arr.size();i++){
        if(arr[i] == "NORTH" && arr[i-1] == "SOUTH" or
           arr[i] == "SOUTH" && arr[i-1] == "NORTH" or
           arr[i] == "WEST" && arr[i-1] == "EAST" or
           arr[i] == "EAST" && arr[i-1] == "WEST"){
          
          arr.erase(arr.begin() + i - 1);
          arr.erase(arr.begin() + i - 1);
          i = 0;
        }
    }
      return arr;
}
};

// ===================== ⚡ Optimized =====================
// O(n) instead of O(n^2): use the result vector as a stack — cancel with the top, otherwise push.
namespace optimized {
class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr){
      auto opposite = [](const std::string& a, const std::string& b) {
        return (a == "NORTH" && b == "SOUTH") || (a == "SOUTH" && b == "NORTH") ||
               (a == "EAST"  && b == "WEST")  || (a == "WEST"  && b == "EAST");
      };
      std::vector<std::string> st;
      for (const auto& d : arr) {
        if (!st.empty() && opposite(st.back(), d)) st.pop_back();
        else st.push_back(d);
      }
      return st;
    }
};
}

/*
💭 First Idea: scan for an adjacent opposite pair, erase both, restart the scan from the beginning.
🧩 Key Property / Invariant: after removing a pair, only the elements now adjacent at that spot can form a new pair.
✅ Key insight: "remove adjacent cancelling pairs repeatedly" is the classic stack pattern (like matching brackets).
🔁 Recognition cue for next time: adjacent pairs annihilate and new neighbours may annihilate -> stack.
⏱  Speed fix for next time: instead of i = 0, step back (i = max(0, i - 2)); better yet use the stack.
🛠  Review: correct; yours O(n^2) → optimized O(n).
*/
