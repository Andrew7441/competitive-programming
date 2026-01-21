#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;

        for(int i = 0; i < (int)nums.size(); i++){
            if(i > k){
                set.erase(nums[i - k - 1]);
            }

            if(set.count(nums[i])){
                return true;
            }

            set.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> nums{1,2,3,1,2,3};

    Solution S;

    cout << boolalpha;
    cout << S.containsNearbyDuplicate(nums, 2);
}