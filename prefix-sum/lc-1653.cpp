// LeetCode 1653 — Minimum Deletions to Make String Balanced
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Topic: prefix-sum | Tags: strings, dynamic-programming
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length(), res = n;
        int a = 0, b = 0;

        for(auto& c: s){
            a += c & 1;     // 'a' = 97 (odd)
        }

        for(auto& c: s){
            a -= c & 1;
            res = min(res, a + b);
            b += ~c & 1;   // 'b' = 98 (even)
        }

        return res;
    }
};

int main() {
	Solution S;
	cout << S.minimumDeletions("aababbab");
	return 0;  
}

/*
Intuition
A balanced string has all ‘‘a" characters appearing before all ‘‘b" characters:

s=‘‘aaaaabbbbbbbbb"
​
 
Any balanced string can be viewed as having a boundary point where all 'a's are to the left and all 'b's are to the right.

For the string to be balanced after deletions, we must choose a position where:

Everything before should be 'a' (delete all 'b's)
Everything after should be 'b' (delete all 'a's)
image.png

image.png

This is essentially a Brute Force approach optimized by Prefix Sum.

By trying every possible boundary position and computing the deletion cost at each point, we guarantee finding the optimal solution. The deletion cost at position i is simply the sum of:

All 'b's encountered so far (must delete from left side)
All 'a's remaining (must delete from right side)

Since we iterate through all positions, we explore all possible ways to partition the string into an 'a' section and a 'b' section, ensuring we find the minimum deletions needed.

Algorithm
We use two counters a and b:

deletions= 
count 
b
​
 
​
 
←
​
 + 
count 
a
​
 
​
 
→
​
 
​
 
where:

b= 
count 
b
​
 
​
 
←
​
  is count of 'b's to the left of current position i, and
a= 
count 
a
​
 
​
 
→
​
  is 'a's count after the current position.
(Precomputed in the first pass).
Simply return the minimum deletions as the result.
*/

/*
💭 First Idea: Try every split point: deletions = b's on the left + a's on the right (two counters).
🧩 Key Property / Invariant: A balanced string is a^x b^y, so pick a boundary; everything left must be 'a' and everything right must be 'b'.
✅ Key insight: Precompute total a's, then sweep once, updating both counts in O(1) per position.
🔁 Recognition cue for next time: "make string sorted/partitioned with min deletions" -> prefix/suffix counts over all split points (or DP: res = min(res+1, countB)).
⏱  Speed fix for next time: One-pass DP: on 'b' cntB++; on 'a' res = min(res + 1, cntB).
🛠  Review: correct (stress-tested vs brute force); main had typo 'Solutin' (compile error), fixed to 'Solution'; O(n) -> Already optimal.
*/
