// LeetCode 3047 — Find the Largest Area of Square Inside Two Rectangles
// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
// Topic: geometry | Tags: math, brute-force
// Complexity (yours): O(n^2) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr){
        long long ans = 0;
        int n = bl.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1;j < n; j++){
                long long bottomx = max(bl[i][0], bl[j][0]);
                long long bottomy = max(bl[i][1], bl[j][1]);

                long long topx = min(tr[i][0], tr[j][0]);
                long long topy = min(tr[i][1], tr[j][1]);

                if(topx < bottomx || topy < bottomy){
                    continue;
                }

                long long height = topy - bottomy;
                long long width = topx - bottomx;
                long long squareSide = min(height, width);
                long long area = squareSide * squareSide;

                ans = max(area, ans);
            }
        }
        return ans;
    }
};

int main() {
    Solution S;

    vector<vector<int>> bottomleft{{1,1},{2,2},{3,1}};
    vector<vector<int>> topright{{3,3},{4,4},{6,6}};

    cout << S.largestSquareArea(bottomleft, topright);
}
/*
💭 First Idea: Try every pair of rectangles, intersect them, take the largest square that fits.
🧩 Key Property / Invariant: Intersection of axis-aligned rectangles = [max of lefts/bottoms, min of rights/tops].
✅ Key insight: The biggest square inside a w x h rectangle has side min(w, h).
🔁 Recognition cue for next time: "Overlap of axis-aligned boxes" -> max of lower corners, min of upper corners.
⏱  Speed fix for next time: Use long long for side*side (side up to 1e7 -> area 1e14).
🛠  Review: correct; Already optimal (n <= 1000, intended O(n^2)).
*/
