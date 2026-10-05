// Codewars — Count the Digit
// Topic: math | Tags: digits, brute-force
// Complexity (yours): O(n log n) time, O(n) space (stores all squares)

/*
Take an integer n (n >= 0) and a digit d (0 <= d <= 9) as an integer.

Square all numbers k (0 <= k <= n) between 0 and n.

Count the numbers of digits d used in the writing of all the k**2.

Implement the function taking n and d as parameters and returning this count.

Examples:
n = 10, d = 1 
the k*k are 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100
We are using the digit 1 in: 1, 16, 81, 100. The total count is then 4.

The function, when given n = 25 and d = 1 as argument, should return 11 since
the k*k that contain the digit 1 are:
1, 16, 81, 100, 121, 144, 169, 196, 361, 441.
So there are 11 digits 1 for the squares of numbers between 0 and 25.
Note that 121 has twice the digit 1.
*/
#include<vector>
#include<string>
using namespace std;

class CountDig
{
public:
    static int nbDig(int n, int d){
      std::string d1 = std::to_string(d);
      std::vector<int> v;
      int count = 0;
      
      for(int i =0; i <= n; i++){
        v.push_back(i*i);
      }
    
      for(int num: v){
        std::string numstr = std::to_string(num);
        for(char c: numstr){
          if(c==d1[0]){
            count++;
          }
        }
      }
      return count;
    } 
};

//BEST PRACTICES
namespace best_practice {  // (added wrapper: same signature as yours, would be a redefinition)

class CountDig
{
public:
    static int nbDig(int n, int d);
};

int CountDig::nbDig(int n, int d) { 
  int count = 0;
  for (int k = 0; k <= n; ++k) {
    int m = k*k;
    do {
      if ((m % 10) == d) count += 1;
      m /= 10;
    } while(m);
  }
  return count;
}
}  // namespace best_practice

/*
💭 First Idea: Store all k² in a vector, then count chars equal to the digit in each to_string.
🧩 Key Property / Invariant: Each k² must be inspected digit by digit; do-while makes 0 count as one digit '0'.
✅ Key insight: No vector needed — count digits of k*k on the fly (the best-practice version).
🔁 Recognition cue for next time: "count digit occurrences over a range" -> % 10 / /= 10 loop per number.
⏱  Speed fix for next time: Skip the vector and the strings: process m = k*k with a do { … } while (m) loop.
🛠  Review: correct; O(n log n) — the best-practice version (already in your file) is the clean one.
*/
