#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
       int n = nums.size();
       vector<int> res(n);

       for(int i = 0; i < nums.size(); i++){
        int idx = (i + nums[i]) % n; 
        if(idx < 0) idx += n;
        res[i] = nums[idx];
       } 
       return res;
    }
};
int main() {
    vector<int> nums{3,-2,1,1};
    Solution s;

    vector<int> result = s.constructTransformedArray(nums);

    for(auto& i: result)
        cout << i << " ";
    
    return 0;
}