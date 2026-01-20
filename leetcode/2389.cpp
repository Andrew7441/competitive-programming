#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for(int i = 1; i < (int)nums.size(); i++){
            nums[i] = nums[i] + nums[i-1];
        }

        for(int& q : queries){
            ans.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        }
        return ans;
    }
};

int main() {
    vector<int> nums{4,5,2,1};
    vector<int> queries{3,10,21};

    Solution S;

    vector<int> res = S.answerQueries(nums, queries);

    for(int i : res){
        cout << i << " ";
    }
}