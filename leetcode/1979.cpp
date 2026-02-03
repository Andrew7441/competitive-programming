#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int greatest = 1;

        int maxe = *max_element(nums.begin(), nums.end());
        int mine = *min_element(nums.begin(), nums.end());

        for(int i = 1; i <= maxe; i++){
            if(mine % i == 0 && maxe % i == 0){
                greatest = i;
            }
        }

        return greatest;
    }
};

int main() {
    Solution S;

    vector<int> nums{{2,5,6,9,10}};

    cout << S.findGCD(nums);
}