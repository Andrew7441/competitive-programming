// LeetCode 85 — Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/
// Topic: stack | Tags: dynamic-programming, matrix, monotonic-stack
// Complexity (yours): O(m²·n) time, O(m·n) space
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

// ===================== ⚡ Optimized =====================
// O(m*n) instead of O(m^2*n): each row is a histogram -> largest rectangle via monotonic stack.
class SolutionOptimized {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> h(n + 1, 0);              // h[n] = 0 is a sentinel that flushes the stack
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) h[j] = (matrix[i][j] == '1') ? h[j] + 1 : 0;
            vector<int> st;                   // indices with increasing heights
            for (int j = 0; j <= n; j++) {
                while (!st.empty() && h[st.back()] >= h[j]) {
                    int height = h[st.back()]; st.pop_back();
                    int left = st.empty() ? -1 : st.back();
                    ans = max(ans, height * (j - left - 1));
                }
                st.push_back(j);
            }
        }
        return ans;
    }
};

/*
💭 First Idea: Per row count consecutive 1s ending at (i,j) (width), then from every cell extend down/up taking min width × height.
🧩 Key Property / Invariant: Column heights of 1s ending at row i form a histogram; the best rectangle with bottom on row i is the largest rectangle in it.
✅ Key insight: Largest rectangle in a histogram = monotonic increasing stack (each popped bar spans prev-smaller..next-smaller).
🔁 Recognition cue for next time: "Largest all-1 rectangle in a binary matrix" → per-row heights + LC 84 histogram stack.
⏱  Speed fix for next time: Even in your version the upward loop is redundant (extending down from every top already covers every rectangle).
🛠  Review: correct; yours O(m²·n) → optimized O(m·n).
*/
