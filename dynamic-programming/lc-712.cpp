// LeetCode 712 — Minimum ASCII Delete Sum for Two Strings
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Topic: dynamic-programming | Tags: strings, lcs
// Complexity (yours): O(n·m) time, O(n·m) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m+1, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1] = dp[i][j] + s1[i];    
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        int total = 0;
        for(char c : s1) total += c;
        for(char c : s2) total += c;

        return total - 2 * dp[n][m];
    }
};

int main() {
    Solution Sol;

    cout << Sol.minimumDeleteSum("sea", "eat");
    
}

/*
💭 First Idea: DP for the max-ASCII-weight common subsequence; answer = total ASCII − 2 · kept.
🧩 Key Property / Invariant: Minimizing deleted ASCII ⇔ maximizing the ASCII sum of the common subsequence that is kept.
✅ Key insight: Plain LCS recurrence with weight s1[i] instead of 1.
🔁 Recognition cue for next time: "Min cost of deletions to make two strings equal" → weighted LCS / edit-distance DP.
⏱  Speed fix for next time: A rolling 1-D dp row gives O(m) space.
🛠  Review: correct; O(n·m) time — Already optimal (space could be O(m)).
*/
