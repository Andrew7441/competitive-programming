// LeetCode 1572 — Matrix Diagonal Sum
// https://leetcode.com/problems/matrix-diagonal-sum/
// Topic: matrix | Tags: arrays
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int r = mat.size();
        int c = mat[0].size();

        for(int i = 0; i < r; i++){
            sum += mat[i][i] + mat[i][r-1-i];
        }

        if(r % 2 == 1){
            sum -= mat[c/2][c/2];
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> mat{{1,2,3},
                            {4,5,6},
                            {7,8,9}};
    Solution Sol;
    
    cout << Sol.diagonalSum(mat) << endl;
}

/*
💭 First Idea: Add mat[i][i] and mat[i][n-1-i] for each row; subtract the centre once if n is odd.
🧩 Key Property / Invariant: The two diagonals share only the centre cell, and only when n is odd.
✅ Key insight: One pass over the rows; no need to visit every cell.
🔁 Recognition cue for next time: "primary + secondary diagonal" -> indices (i,i) and (i,n-1-i).
⏱  Speed fix for next time: For a square matrix r == c, so mat[r/2][r/2] would be clearer.
🛠  Review: correct; O(n) -> Already optimal.
*/
