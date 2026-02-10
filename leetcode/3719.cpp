#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;        

        for(int i = 0; i < n; i++){
            unordered_set<int> even;
            unordered_set<int> odd;
            for(int j = i; j < n; j++){
                if(nums[j] % 2){
                    even.insert(nums[j]);
                }else{
                    odd.insert(nums[j]);
                }

                if(even.size() == odd.size()){
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans; 
    }
};


int main() {
	vector<int> nums{3,2,2,5,4};
	Solution S;
	cout << S.longestBalanced(nums);
	return 0;
}

/*
2nd example:
there are 2 distinct even and odd numbers. However there contains a duplicate
but that doesnt change the distinct count, so take the whole subarray.

3rd example:
Whole array [1,2,3,2]
Distinct evens → {2} → 1
Distinct odds → {1,3} → 2
❌ Not balanced → so length 4 is invalid.
So 1 cant be counted

Subarray [2,3,2]
Distinct evens → {2} → 1
Distinct odds → {3} → 1
✅ Balanced → length = 3
*/
