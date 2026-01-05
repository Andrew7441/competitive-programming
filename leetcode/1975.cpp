#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        long long smallest = LLONG_MAX;
        int negcount = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += abs(matrix[i][j]);

                if(abs(matrix[i][j]) < smallest){
                    smallest = abs(matrix[i][j]);
                }
                if(matrix[i][j] < 0){
                    negcount++;
                }
            }
        }

        if(negcount % 2 == 0){
            return sum;
        }
        return sum - 2 * smallest; 
    }
};

int main() {
    Solution Sol;

    vector<vector<int>> matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};

    cout << Sol.maxMatrixSum(matrix);
    
}