#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;

        for(int i = 0; i < nums.size(); i+=2){
            sum += nums[i];
        }

        return sum;
    }
};


int main() {
	vector<int> nums{6,2,6,5,1,2};
	Solution S;
	cout << S.arrayPairSum(nums);
	return 0;
}

/*

 Intuition
When pairing elements to maximize the sum of the minimums in each pair, the optimal strategy is to pair the smallest numbers together. This way, we don't "waste" large numbers as minimums.

🛠️ Approach
Sort the array.
The optimal pairs are formed by taking every two elements as a pair (since after sorting, the first of each pair is always the smaller one).
Add up every even-indexed element (i.e., the smaller in each pair).
Return the final sum.
This works because sorting ensures that for every pair (a, b) where a <= b, using a in the sum of minimums gives us the maximum total possible.

⏱️ Complexity
Time complexity:
O(nlogn) – due to sorting the array.

Space complexity:
O(1) – if sorting is done in place.
*/
