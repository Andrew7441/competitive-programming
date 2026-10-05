// Practice — Binary Search
// Topic: binary-search | Tags: arrays
// Complexity (yours): O(log n) time, O(1) space
// ⚠️ Review: while (l < r) skips the case l == r, so e.g. target 9 in [1,3,5,7,9] (or any 1-element array) returns -1; see corrected version below.
// Source: split from codeforces/practice.cpp (original problem statement below)
// Binary Search
//
// Write a function that implements binary search on a sorted array. Return the index of the target, or -1 if not found.
// Example: binary_search([1, 3, 5, 7, 9], 5) → 2

#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>& nums, int target){
    int l = 0, r = nums.size() - 1;

    while(l < r){
        int mid = (l + r) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    return -1;
}

int main(){

    vector<int> v{1, 3, 5, 7, 9};
    cout << BinarySearch(v, 10);

    return 0;
}

// ===================== ⚡ Optimized =====================
// Fix: loop while l <= r so the last remaining candidate is also checked; overflow-safe mid.
namespace optimized {
int BinarySearch(vector<int>& nums, int target) {
    int l = 0, r = (int)nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
}

/*
💭 First Idea: Classic binary search on a closed interval [l, r].
🧩 Key Property / Invariant: With a closed interval [l, r] the search space is non-empty while l <= r.
✅ Key insight: Closed interval -> while (l <= r) with r = mid - 1; half-open [l, r) -> while (l < r) with r = mid. Do not mix them.
🔁 Recognition cue for next time: Any "sorted array, find index" -> pick one interval convention and stick to it.
⏱  Speed fix for next time: Test the first, last, missing and single-element cases right after writing a binary search.
🛠  Review: wrong (misses the element when l == r, e.g. last element or 1-element array); O(log n) fixed version added.
*/
