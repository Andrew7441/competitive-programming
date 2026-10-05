// LeetCode 1266 — Minimum Time Visiting All Points
// https://leetcode.com/problems/minimum-time-visiting-all-points/
// Topic: geometry | Tags: math, arrays
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;

        for(int i = 1; i < (int)points.size(); i++){
            res += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
        }
        return res; 
    }
};

int main() {

    vector<vector<int>> matrix{{1,1},
                               {3,4},
                               {-1,0}};


    Solution Sol;

    cout << Sol.minTimeToVisitAllPoints(matrix) << endl;
    
}

/*
💭 First Idea: Sum over consecutive points of max(|dx|, |dy|).
🧩 Key Property / Invariant: A diagonal step fixes x and y at once, so the cost between two points is the Chebyshev distance.
✅ Key insight: Move diagonally until one coordinate matches, then straight: time = max(dx, dy).
🔁 Recognition cue for next time: 8-direction moves on a grid, each costing 1 -> Chebyshev distance max(|dx|,|dy|).
⏱  Speed fix for next time: No search needed; points must be visited in order, so just add up the segments.
🛠  Review: correct; O(n) -> Already optimal.
*/
