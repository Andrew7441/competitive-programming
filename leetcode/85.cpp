#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> mat(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = matrix[i][j] - '0';
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                if(mat[i][j] == 1){
                    mat[i][j] += mat[i][j-1];
                }
            }
        }

        int ans = 0;

        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                int width = mat[i][j];
                if(width == 0) continue;

                int curwidth = width;
                for(int k = i; k < m && mat[k][j] > 0; k++){
                    curwidth = min(curwidth, mat[k][j]);
                    int height = k - i + 1;
                    ans = max(ans, curwidth * height);
                }


                curwidth = width;
                for(int k = i; k >= 0 && mat[k][j] > 0; k--){
                    curwidth = min(curwidth, mat[k][j]);
                    int height = i - k + 1;
                    ans = max(ans, curwidth * height);
                }
            }
        }
        return ans;
    }
};

int main() {

    vector<vector<char>> matrix= {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    Solution Sol;

    cout << Sol.maximalRectangle(matrix) << endl;
    
}