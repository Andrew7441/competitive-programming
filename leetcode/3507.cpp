#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool nonDecrease(vector<int>& n){
        for(int i = 0; i < (int)n.size() - 1; i++){
            if(n[i] > n[i+1]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;

        while(!nonDecrease(nums) && nums.size() > 1){
            int mini = INT_MAX;
            int idx = -1;
            for(int i = 0; i < (int)nums.size()-1; i++){
                int sum = nums[i] + nums[i+1];
                if(sum < mini){
                    mini = sum;
                    idx = i;
                }
            }
            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx + 1);
            op++;
        }
        return op;
    }
};

int main() {
    vector<int> nums{5,2,3,1};

    Solution S;

    cout << S.minimumPairRemoval(nums) << endl;
    
}

/*
Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

The array nums is already sorted.
*/