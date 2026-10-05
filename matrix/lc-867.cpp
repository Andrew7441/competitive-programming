// LeetCode 867 — Transpose Matrix
// https://leetcode.com/problems/transpose-matrix/
// Topic: matrix | Tags: arrays
// Complexity (yours): O(m·n) time, O(m·n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> res(col, vector<int>(row)); 
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                res[j][i] = matrix[i][j];
            }
        }
        return res; 

    }
};

int main() {

    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};

    Solution Sol;
    vector<vector<int>> res = Sol.transpose(matrix);

    cout << "Before:" << endl;

    for(size_t i = 0; i < res.size(); i++){
        for(size_t j = 0; j < res[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "After:" << endl;

    for(size_t i = 0; i < res.size(); i++){
        for(size_t j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
}

/*
💭 First Idea: Allocate a col × row result and set res[j][i] = matrix[i][j].
🧩 Key Property / Invariant: Transpose swaps the dimensions: m × n → n × m.
✅ Key insight: Non-square input needs a new matrix (in-place swapping only works for square ones).
🔁 Recognition cue for next time: "Flip over the main diagonal" → index swap.
⏱  Speed fix for next time: Your main's "Before" loop uses res's dimensions for matrix — only fine because the test is square.
🛠  Review: correct; O(m·n) — Already optimal.
*/
