// LeetCode 605 — Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/
// Topic: greedy | Tags: arrays
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int x = flowerbed.size();

        for(int i = 0; i < (int)flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                bool leftempty = (i == 0 || flowerbed[i-1] == 0);
                bool rightempty = (i == x - 1 || flowerbed[i + 1] == 0);
                if(leftempty && rightempty){
                    n--;
                    flowerbed[i]= 1;
                    if(n <= 0) return true;
                }
            }
            
        }
        return n <= 0;
    }
};

int main() {

    vector<int> flowerbed{1,0,0,0,1};

    Solution S;

    cout << S.canPlaceFlowers(flowerbed, 1);
    
}

/*
💭 First Idea: Greedy left to right: plant whenever the spot and both neighbours are empty.
🧩 Key Property / Invariant: Planting at the earliest possible spot never blocks more later spots than skipping it would.
✅ Key insight: Out-of-bounds neighbours count as empty; stop early once n <= 0.
🔁 Recognition cue for next time: "Max non-adjacent placements in a line" → greedy scan.
⏱  Speed fix for next time: Copy flowerbed first if the caller's input must not be mutated.
🛠  Review: correct; O(n) — Already optimal.
*/
