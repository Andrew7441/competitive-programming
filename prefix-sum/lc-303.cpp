// LeetCode 303 — Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/
// Topic: prefix-sum | Tags: design, arrays
// Complexity (yours): O(n) per query, O(n) space
#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> numbers; 

    NumArray(vector<int>& nums) : numbers{nums} {
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        while(left <= right){
            sum += numbers[left++];
        }
        return sum;
    }
};

int main() {
    vector<int> nums{-2, 0, 3, -5, 2, -1};

    NumArray* array = new NumArray(nums);

    vector<int> res; 
    
    int p1 = array->sumRange(0,2);
    int p2 = array->sumRange(2,5);
    int p3 = array->sumRange(0,5);
    
    res.push_back(p1);
    res.push_back(p2);
    res.push_back(p3);

    cout << "[ ";
    for(int i : res){
        cout << i << ", ";
    }
    cout << "]";
}

// ===================== ⚡ Optimized =====================
// O(1) per query instead of O(n): prefix sums built once in the constructor.
class NumArrayOptimized {
public:
    vector<long long> pre;  // pre[i] = nums[0] + ... + nums[i-1]
    NumArrayOptimized(vector<int>& nums) : pre(nums.size() + 1, 0) {
        for (size_t i = 0; i < nums.size(); i++) pre[i + 1] = pre[i] + nums[i];
    }
    int sumRange(int left, int right) { return (int)(pre[right + 1] - pre[left]); }
};

/*
💭 First Idea: Store the array and loop left..right on every query.
🧩 Key Property / Invariant: sum(l..r) = pre[r+1] - pre[l], where pre[i] = sum of the first i elements.
✅ Key insight: Data never changes → precompute prefix sums once, answer every query in O(1).
🔁 Recognition cue for next time: "Many range-sum queries, no updates" → prefix sums (with updates → Fenwick / segment tree).
⏱  Speed fix for next time: Make pre size n+1 with pre[0] = 0 so l = 0 needs no special case.
🛠  Review: correct (passes, but slow); yours O(n) per query → optimized O(1) per query after O(n) build.
*/
