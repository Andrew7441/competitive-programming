// LeetCode 561 — Array Partition
// https://leetcode.com/problems/array-partition/
// Topic: greedy | Tags: sorting
// Complexity (yours): O(n log n) time, O(1) extra space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;

        for(int i = 0; i < nums.size(); i+=2){
            sum += nums[i];
        }

        return sum;
    }
};


int main() {
	vector<int> nums{6,2,6,5,1,2};
	Solution S;
	cout << S.arrayPairSum(nums);
	return 0;
}

/*

 Intuition
When pairing elements to maximize the sum of the minimums in each pair, the optimal strategy is to pair the smallest numbers together. This way, we don't "waste" large numbers as minimums.

🛠️ Approach
Sort the array.
The optimal pairs are formed by taking every two elements as a pair (since after sorting, the first of each pair is always the smaller one).
Add up every even-indexed element (i.e., the smaller in each pair).
Return the final sum.
This works because sorting ensures that for every pair (a, b) where a <= b, using a in the sum of minimums gives us the maximum total possible.

⏱️ Complexity
Time complexity:
O(nlogn) – due to sorting the array.

Space complexity:
O(1) – if sorting is done in place.
*/

/*
💭 First Idea: Sort and sum every even-indexed element (pair neighbours).
🧩 Key Property / Invariant: In sorted order the smallest element is always some pair's min; pairing it with the 2nd smallest wastes the least.
✅ Key insight: Exchange argument: any pairing can be swapped into adjacent sorted pairs without lowering the sum.
🔁 Recognition cue for next time: "Maximize sum of min(a_i, b_i) over pairs" → sort + pair neighbours.
⏱  Speed fix for next time: Values are in [-1e4, 1e4], so counting sort gives O(n + range) if ever needed.
🛠  Review: correct; O(n log n) — Already optimal (counting sort O(n + R) is the only alternative).
*/
