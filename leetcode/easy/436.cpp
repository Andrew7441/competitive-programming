#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        set<pair<int,int>> visit;

        function<int(int,int)> dfs = [&](int i, int j) -> int {
            if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) {
                return 1;
            }

            if (visit.count({i, j})) {
                return 0;
            }

            visit.insert({i, j});

            int perim = 0;
            perim += dfs(i, j + 1);
            perim += dfs(i + 1, j);
            perim += dfs(i, j - 1);
            perim += dfs(i - 1, j);

            return perim;
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j);
                }
            }
        }

        return 0;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    Solution sol;
    cout << sol.islandPerimeter(grid) << endl;

    return 0;
}