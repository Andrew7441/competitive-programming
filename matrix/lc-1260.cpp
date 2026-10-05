// LeetCode 1260 — Shift 2D Grid
// https://leetcode.com/problems/shift-2d-grid/
// Topic: matrix | Tags: math, arrays
// Complexity (yours): O(n·m) time, O(n·m) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int newJ = (j + k) % m;
                int newI = (i + (j+k)/m) % n;
                ans[newI][newJ] = grid[i][j];
            }
        }
        return ans;
    }
};

int main() {
    Solution Sol;

    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};

    cout << "Before Shift:" << endl;
    for(auto &row : grid){
        cout << "[ ";
        for(int i : row){
            cout << i << " ";
        }
        cout << "]" << endl;
    }


    vector<vector<int>> shifted = Sol.shiftGrid(grid, 1);
    
    cout << "After Shift:" << endl;
    for(auto &row : shifted){
        cout << "[ ";
        for(int i : row){
            cout << i << " ";
        }
        cout << "]" << endl;
    }
}

/*
💭 First Idea: Compute each element's destination directly: column (j+k) % m, row (i + (j+k)/m) % n.
🧩 Key Property / Invariant: Shifting k times = rotating the row-major flattened array right by k.
✅ Key insight: Flat index p = i*m + j moves to (p + k) % (n*m).
🔁 Recognition cue for next time: "Shift/rotate a 2D grid" → flatten indices.
⏱  Speed fix for next time: Do k %= n*m first if k can be huge.
🛠  Review: correct; O(n·m) — Already optimal.
*/
