// LeetCode 2267 — Check if There Is a Valid Parentheses String Path
// https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
// Topic: dynamic-programming | Tags: matrix, strings
// Complexity (yours): O(m*n*(m+n)) time, O(m*n*(m+n)) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int len = m + n - 1;

        //edge case - valid paren should be even
        if(len % 2) return false;
        //edge case - valid paren should start with '('
        if(grid[0][0] == ')') return false;

        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n, 
                vector<bool>(len + 1, false)
            )
        );

        dp[0][0][1] = true;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;

                for(int balance = 0; balance <= len; balance++) {
                    int prevBal;
                    if(grid[i][j] == '('){
                        prevBal = balance - 1;
                    }
                    else {
                        prevBal = balance + 1;
                    }

                    if(prevBal < 0 || prevBal > len) continue;

                    //come from top
                    if(i > 0 && dp[i-1][j][prevBal]){
                        dp[i][j][balance] = true;
                    }
                    //come from left
                    if(j > 0 && dp[i][j-1][prevBal]){
                        dp[i][j][balance] = true;
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'(', '(', '('},
        {')', '(', ')'},
        {'(', '(', ')'},
        {'(', '(', ')'}
    };

    cout << boolalpha << sol.hasValidPath(grid) << '\n';

    return 0;
}
/*
💭 First Idea: 3D reachability DP: dp[i][j][b] = can we reach (i,j) with open-minus-close balance b.
🧩 Key Property / Invariant: Along any path the balance must never drop below 0 and must be exactly 0 at the end.
✅ Key insight: Position alone is not enough state; add the running balance (<= m+n-1) as a DP dimension.
🔁 Recognition cue for next time: Grid path + constraint on a running count (parentheses, sum mod k) -> dp[i][j][value].
⏱  Speed fix for next time: Also prune: grid[m-1][n-1]=='(' -> false, and skip balances larger than cells left; bitset<200> per cell makes it ~64x faster.
🛠  Review: correct; Already optimal (O(m*n*(m+n)) is the intended bound).
*/
