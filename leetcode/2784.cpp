#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> base(n);

        std::iota(base.begin(), base.end(), 1);
        base[n - 1] = n - 1;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(base[i] != nums[i]) return false;
        }

        return true;
    }
};
int main() {
    Solution S;
    vector<int> nums{3, 4, 4, 1, 2, 1};

    cout << boolalpha;
    cout << S.isGood(nums);
    
    return 0;
}

/*
💭 first idea
🧩 key property / invariant
✅ key insight
🔁 recognition cue for next time
⏱ speed fix for next time
*/