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