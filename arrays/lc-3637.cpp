// LeetCode 3637 — Trionic Array I
// https://leetcode.com/problems/trionic-array-i/
// Topic: arrays | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 0;

        if(n < 4) return false;    

        // strictly increasing 
        while(i + 1 < n && nums[i] < nums[i+1]) i++;
        if(i == 0) return false;
        int p = i;

        // strictly decreasing
        while(i + 1 < n && nums[i] > nums[i+1]) i++;
        if(i == p) return false;
        int q = i;

        //strictly increasing
        while(i + 1 < n && nums[i] < nums[i+1]) i++;
        

        return i == n - 1 && q < n - 1;
    }
};

int main() {
	vector<int> vec{1,3,5,4,2,6};
	Solution S;
	cout << boolalpha <<  S.isTrionic(vec) << "\n";
	return 0;
}

/*
💭 First Idea: Walk once: climb a strictly increasing run, then a strictly decreasing run, then an increasing run to the end.
🧩 Key Property / Invariant: Each of the three runs must have length >= 2 (move at least one step) and the last must reach n-1.
✅ Key insight: Greedy maximal runs: the first peak and first valley are forced.
🔁 Recognition cue for next time: "Array shape is up/down/up" -> three while-loops with a pointer, check each moved.
⏱  Speed fix for next time: Check 'pointer moved' after every phase (i == 0, i == p, q < n-1) - exactly what you did.
🛠  Review: correct; Already optimal.
*/
