// LeetCode 1566 — Detect Pattern of Length M Repeated K or More Times
// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
// Topic: arrays | Tags: sliding-window
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int c = 0;

        for(int i = 0; i + m < (int)arr.size(); i++){
            if(arr[i] != arr[i+m])
                c = 0;

            c += (arr[i] == arr[i+m]);   

            if(c == (k-1)*m) return true;
        }

        return false;
    }
};

int main() {
    cout << boolalpha;
    vector<int> arr{1,2,4,4,4,4};
    int m = 1, k = 3;

    Solution S;

    cout << S.containsPattern(arr, m, k);
}

/*
💭 First Idea: Count consecutive i with arr[i] == arr[i+m]; success when the streak reaches (k-1)*m.
🧩 Key Property / Invariant: A block of length m repeated k times means arr[i] == arr[i+m] for (k-1)*m consecutive positions.
✅ Key insight: Compare with a shift of m instead of extracting patterns, which turns O(n·m·k) into O(n).
🔁 Recognition cue for next time: "periodic block repeated k times" -> compare arr[i] with arr[i+period] and track the streak.
⏱  Speed fix for next time: Reset the streak on a mismatch; no substring building needed.
🛠  Review: correct (stress-tested vs brute force); O(n) -> Already optimal.
*/
