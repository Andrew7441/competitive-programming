// LeetCode 3453 — Separate Squares I
// https://leetcode.com/problems/separate-squares-i/
// Topic: binary-search | Tags: geometry, sweep-line
// Complexity (yours): O(n * log(2e9/1e-5)) ~ O(48n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBelowAreaGreater(vector<vector<int>>& squares, double mid){
        double belowarea = 0;
        double abovearea = 0;

        for(int i = 0; i < (int)squares.size(); i++){
            double bottomY = squares[i][1];
            double side = squares[i][2];
            double topY = bottomY + side;

            if(topY <= mid){
                belowarea += (side * side);
            }else if(bottomY >= mid){
                abovearea += (side * side);
            }else{
                double bottom = mid - bottomY;
                double top = topY - mid;
                belowarea += (bottom * side);
                abovearea += (top * side);
            }
        }
        return belowarea >= abovearea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 0;
        double high = 2e9;
        double precision = 1e-5;

        while(high - low > precision){
            double mid = (low + high) / 2;
            if(isBelowAreaGreater(squares, mid)){
                high = mid; 
            }else{
                low = mid;
            }
        }
        return low;
    }
};

int main() {
    vector<vector<int>> squares{{0,0,1},{2,2,1}};

    Solution S;

    cout << S.separateSquares(squares);
}

// ===================== ⚡ Optimized =====================
// Exact sweep instead of floating binary search: sort bottom/top events by y,
// accumulate area strip by strip (width = sum of active sides); stop at total/2.
class SolutionOptimized {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<pair<long long, long long>> ev;   // (y, change in total width)
        long double total = 0;
        for (auto& s : squares) {
            long long y = s[1], l = s[2];
            total += (long double)l * l;
            ev.push_back({y, l});
            ev.push_back({y + l, -l});
        }
        sort(ev.begin(), ev.end());
        long double half = total / 2, acc = 0, width = 0;
        long long prevY = ev[0].first;
        for (auto& [y, dw] : ev) {
            if (width > 0 && acc + width * (y - prevY) >= half)
                return (double)(prevY + (half - acc) / width);
            acc += width * (y - prevY);
            width += dw;
            prevY = y;
        }
        return (double)prevY;
    }
};

/*
💭 First Idea: Binary search on the line y: if area below >= area above, move down, else move up.
🧩 Key Property / Invariant: areaBelow(y) - areaAbove(y) is monotone non-decreasing in y.
✅ Key insight: Monotone predicate on a real-valued answer -> binary search on doubles until high-low < eps.
🔁 Recognition cue for next time: "Find the y that splits area/amount in half" -> binary search on the answer, or sweep with prefix area.
⏱  Speed fix for next time: Iterate a fixed 60-100 times instead of a precision loop; or sweep sorted y-events for an exact answer.
🛠  Review: correct (max error ~7e-6 in stress test, just inside 1e-5); exact O(n log n) sweep added below (no precision risk).
*/
