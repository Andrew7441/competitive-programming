// Codewars — Computer problem series #1: Fill the Hard Disk Drive
// Topic: arrays | Tags: prefix-sum, greedy
// Complexity (yours): O(n) time, O(1) space
// From: Codewars/Functions July 2024.md — section "(untitled: "how many files of the copy queue you will be able to save")"
/*
Kata description:
Your task is to determine how many files of the copy queue you will be able to save into your Hard Disk Drive. The files must be saved in the order they appear in the queue.
Zero size files can always be saved even HD full.
Input: array of file sizes (0 <= s <= 100), capacity of the HD (0 <= c <= 500).
Output: number of files that can be fully saved in the HD.
exs:
save([4,4,4,3,3], 12) -> 3
# 4+4+4 <= 12, but 4+4+4+3 > 12
*/

#include <vector>

int save(std::vector<int> s, int hd) {
  int sum=0, count=0;
  for(int i : s){
    if(sum + i <= hd){
      sum+= i;
      count++;
    }else{
      break;
    }
  }
  return count;
  
}

/*
💭 First Idea: Running sum; count files while sum + size <= capacity, break otherwise.
🧩 Key Property / Invariant: Files are saved in order, so the answer is the longest prefix whose sum fits.
✅ Key insight: Stop at the first file that does not fit (later ones cannot be saved out of order).
🔁 Recognition cue for next time: "how many in order fit within a budget" -> prefix sum until it exceeds.
⏱  Speed fix for next time: Nothing to speed up.
🛠  Review: correct; O(n) -> Already optimal.
*/
