#include <bits/stdc++.h>
using namespace std;

/*Time Limit Exceeded
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, vector<long long>> mp;
        vector<long long> res(n);

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto& p : mp){
            vector<long long>& v = p.second;

            for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < v.size(); j++){
                    if(i != j){
                        res[v[i]] += abs(v[i] - v[j]);
                    }
                }
            }
        }

        return res;
    }
};*/

/*
https://leetcode.com/problems/sum-of-distances/?envType=daily-question&envId=2026-04-23
*/

//Further optimization
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, vector<long long>> mp;
        vector<long long> res(n);

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto& p : mp){
            vector<long long>& v = p.second;

            long long sum = accumulate(v.begin(), v.end(), 0LL);

            long long leftSum = 0;
            int m = v.size();

            for(int i = 0; i < m; i++){
                long long rightSum = sum - leftSum - v[i];

                long long left = 1LL * v[i] * i - leftSum;
                long long right = rightSum - 1LL * v[i] * (m - i - 1);

                res[v[i]] = left + right;
                leftSum += v[i];
            }
        }

        return res;
    }
};



int main() {

    Solution S;
    vector<int> nums{1,3,1,1,2};

    vector<long long> res = S.distance(nums);

    for(int i : res) cout << i << " ";


    return 0;
}

/*
💭 first idea
Group equal values by indices, then for each index sum distances to every
other equal index

🧩 key property / invariant
For a sorted index list of the same value, distances split cleanly into
contribution from indices on the left and indices on the right

✅ key insight
Using prefix sums let each index's total distance be computed in O(1) within
its group instead of comparing against every other index

🔁 recognition cue for next time
When a problem asks for sum of absolute differences over repeated values, 
think group indices + prefix sums on sorted positions

⏱ speed fix for next time
As soon as I see nested loops inside each equal-value group, replace pairwise distance calculation with left-sum/right-sum formulas.
*/