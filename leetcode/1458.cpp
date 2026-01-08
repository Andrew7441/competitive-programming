#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, int n, int m, vector<vector<int>>& dp){
        if(i == n || j == m) return -1e9; // Not INT_MIN because integer overflow 

        if(dp[i][j] != -1e9){
            return dp[i][j];
        }

        int val = nums1[i] * nums2[j];

        int take_both = (nums1[i] * nums2[j]) + solve(nums1, nums2, i + 1, j + 1, n, m, dp);
        int skip_i = solve(nums1, nums2, i + 1, j, n, m, dp);
        int skip_j = solve(nums1, nums2, i, j + 1, n, m, dp);

        return dp[i][j] = max({val, take_both, skip_i, skip_j,});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1e9));

        return solve(nums1, nums2, 0, 0, n, m, dp);
    }
};
int main() {
    Solution Sol;

    vector<int> nums1{2,1,-2,5};
    vector<int> nums2{3,0,-6};

    cout << Sol.maxDotProduct(nums1, nums2);

}

/* Example: 
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.

*/

/*
So Dot product is basically multiplying element by element  so 2 * 3

Will use Longest Common Subsequence analogy because i have a lot of combinations.
its not simply choosing or skipping a particular number helps me maximize my dot product
So its basically checking all possible solutions/combinations and choosing the best one, which requires
Dynamic Programming. Greedy doesnt work because theres no selection procedure

Will Solve using Recursion and Memoization

So i will either recursively call on both elements i and j, or skip i take j, or skip j take i.
I cant skip both because question specifies that i cant take non empty subsequences 

*/