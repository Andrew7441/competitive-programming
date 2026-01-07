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