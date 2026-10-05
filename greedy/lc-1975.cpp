// LeetCode 1975 — Maximum Matrix Sum
// https://leetcode.com/problems/maximum-matrix-sum/
// Topic: greedy | Tags: matrix, math
// Complexity (yours): O(n²) time, O(1) space
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

/*
💭 First Idea: Sum the absolute values; if the number of negatives is odd, subtract 2 * the smallest |x|.
🧩 Key Property / Invariant: Flipping adjacent pairs preserves the parity of negatives and can move a minus sign anywhere.
✅ Key insight: With even parity everything can be made non-negative; with odd parity exactly one cell (the smallest |x|) stays negative.
🔁 Recognition cue for next time: "flip signs of pairs any number of times" -> parity invariant + push the leftover sign onto the min |x|.
⏱  Speed fix for next time: A zero absorbs the odd sign for free; smallest = 0 already covers that.
🛠  Review: correct (verified vs BFS brute force on small grids); O(n²) -> Already optimal.
*/
