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