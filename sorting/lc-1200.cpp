// LeetCode 1200 — Minimum Absolute Difference
// https://leetcode.com/problems/minimum-absolute-difference/
// Topic: sorting | Tags: arrays
// Complexity (yours): O(n log n) time, O(1) extra space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int mindiff = INT_MAX;

        for(int i = 1; i < (int)arr.size(); i++){
            if(arr[i] - arr[i-1] < mindiff){
                mindiff = arr[i] - arr[i-1];
            }
        }

        vector<vector<int>> res;
        for(int i = 1; i < (int)arr.size(); i++){
            if(arr[i] - arr[i-1] == mindiff){
                vector<int> pair;
                pair.push_back(arr[i-1]);
                pair.push_back(arr[i]);
                res.push_back(pair);
            }
        }
        return res; 
    }
};

int main() {
    vector<int> arr = {4, 2, 1, 3};

    Solution S;

    vector<vector<int>> res = S.minimumAbsDifference(arr);

    for(int i = 0; i < (int)res.size(); i++){
        for(int j = 0; j < (int)res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
}

/*
I can see myself getting better in real time and i couldnt be more thankful.
I love myself and i love the suffering which inevitably leads to better 
thought processes and faster thinking. 

I solved this question in under 5 min. I am so proud of myself.
*/

/*
💭 First Idea: Sort, find the min adjacent difference, then collect all adjacent pairs with that difference.
🧩 Key Property / Invariant: After sorting, the minimum absolute difference is always between neighbours.
✅ Key insight: Two passes (or one pass that clears the result when a smaller diff appears).
🔁 Recognition cue for next time: "Min difference among all pairs" → sort + adjacent scan.
⏱  Speed fix for next time: res.push_back({arr[i-1], arr[i]}) directly instead of building a temp vector.
🛠  Review: correct; O(n log n) — Already optimal.
*/
