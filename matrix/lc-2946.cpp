// LeetCode 2946 — Matrix Similarity After Cyclic Shifts
// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
// Topic: matrix | Tags: simulation
// Complexity (yours): O(m*n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != mat[i][(j + k) % n]) return false;
            }
        }
        return true;
    }
};

int main() {

    vector<vector<int>> mat{{1,2,1,2},{5,5,5,5},{6,3,6,3}};
    int k = 2;

    Solution S;

    cout << boolalpha;
    cout << S.areSimilar(mat, k);

}
/*
💭 First Idea: Check every cell against the cell k positions to its right (cyclically).
🧩 Key Property / Invariant: A row is unchanged by a left OR right shift of k iff row[j] == row[(j+k) % n] for all j.
✅ Key insight: Left vs right shift direction doesn't matter: a row invariant under shift k is invariant under -k too.
🔁 Recognition cue for next time: "Same after cyclic shift by k" -> compare a[j] with a[(j+k) % n], no actual shifting.
⏱  Speed fix for next time: Don't simulate the k shifts; reduce k mod n and compare once.
🛠  Review: correct; Already optimal.
*/
