// LeetCode 2418 — Sort the People
// https://leetcode.com/problems/sort-the-people/
// Topic: sorting | Tags: arrays
// Complexity (yours): O(n log n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string, int>> v;

        for(int i = 0; i < n; i++){
            v.push_back({names[i], heights[i]});
        }
        sort(v.begin(), v.end(),[](const pair<string, int>& a, const pair<string, int>& b){
            return a.second > b.second;
        });

        vector<string> res(n);
        for(int i = 0; i < n; i++){
            res[i] = v[i].first;
        }

        return res;
    }
};

int main() {
    vector<string> names{"Mary","John","Emma"};
    vector<int> heights{180,165,170};

    Solution S;

    vector<string> New_Names  = S.sortPeople(names, heights);

    for(auto i : New_Names)
        cout << i << " ";

    
}
/*
💭 First Idea: Pair (name, height), sort by height descending, read names back.
🧩 Key Property / Invariant: Heights are distinct, so ordering by height alone is a total order.
✅ Key insight: Sort indices/pairs by the key array, then project out the other array.
🔁 Recognition cue for next time: "Reorder array A by values of array B" -> sort pairs or an index array by B.
⏱  Speed fix for next time: Sort an index vector with a lambda on heights to avoid copying strings.
🛠  Review: correct; Already optimal.
*/
