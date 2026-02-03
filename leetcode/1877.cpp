#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> v;
        int i = 0, j = nums.size() - 1;

        while(i < j){
            v.push_back({nums[i], nums[j]});
            i++;
            j--;
        }
        int max = INT_MIN;
        for(auto& p : v){
            int sum = p.first + p.second;
            if(sum > max){
                max = sum;
            }
        }
        return max;

    }
};

int main() {
    vector<int> nums{3,5,4,2,4,6};

    Solution S;

    cout << S.minPairSum(nums);
}