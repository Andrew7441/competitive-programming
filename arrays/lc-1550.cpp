// LeetCode 1550 — Three Consecutive Odds
// https://leetcode.com/problems/three-consecutive-odds/
// Topic: arrays | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 1; i < (int)arr.size() - 1; i++){
            if(arr[i-1] % 2 != 0 && arr[i] % 2 != 0 && arr[i+1] % 2 != 0){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution S;

    vector<int> arr{1,2,34,3,4,5,7,23,12};

    cout << boolalpha;
    cout << S.threeConsecutiveOdds(arr);
    
}

/*
💭 First Idea: Check every window of 3 for all-odd.
🧩 Key Property / Invariant: Any run of >= 3 odds contains such a window.
✅ Key insight: Alternatively keep a running count of consecutive odds and reset it on an even number.
🔁 Recognition cue for next time: "k consecutive elements with property" -> running streak counter.
⏱  Speed fix for next time: The (int)size() cast avoids unsigned underflow for tiny arrays; keep that habit.
🛠  Review: correct; O(n) -> Already optimal.
*/
