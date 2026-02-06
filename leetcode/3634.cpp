#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++){
            while(j + 1 < n && (long long)nums[i] * k >= nums[j + 1]){
                j += 1;
            }
            ans = max(ans, j - i + 1);
        }
        return n - ans;
    }
};

int main() {
	Solution S;
	vector<int> nums{1,6,2,9};
	int k = 3;
	cout << S.minRemoval(nums, k);
	return 0;  
}

/*

First of all, let's see that sorting the array nums could only help us.
Let's suppose we fix some element and say that it is the minimal one that we are going to keep.

If this element has a value of x, then all of the elements with values in the range [x,k∗x] can stay, and others must be removed.
Since we work with a range of values, it is in our best interest to sort the array.

Brute Force
Since the array is sorted now, we can say that the minimal element that we are going to keep is at position i. Next, we can see that the elements that we can keep are elements in some subarray [i,j].
More specifically, for sorted nums and given i(the position of the minimal element that we keep), we need to find the largest j where nums[j]≤nums[i]∗k.
This way we will keep j−i+1 elements, i.e., all of the elements inside of the subarray [i,j].

The naive way is to use a for loop to find such j for each i, which brings us to a brute force solution that passes 966 / 985 test cases:

int n = (int)nums.size();
sort(nums.begin(), nums.end());
int ans = 0;
for(int i = 0; i < n; i ++){
    for(int j = i; j < n; j ++){
        if(nums[j] <= (long long)nums[i] * k){
            ans = max(ans, j - i + 1);
        }
        else break;
    }
}
return n - ans;
Upper Bound - Binary Search
Now, if we want to optimize this solution, we can use built-in functions such as upper_bound in C++.

upper_bound
This gives us a little bit of messy code that gets AC:

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n; i ++){
            int max_val = min((long long)2e9, (long long)k * nums[i]);
            int j = upper_bound(nums.begin(), nums.end(), max_val) - nums.begin();
            j --;
            ans = max(ans, j - i + 1);
        }
        return n - ans;
    }
};
Two Pointers
The most elegant way, however, is to use the two-pointer method.

After sorting the array, all the numbers are in increasing order.
This makes it easier to look at continuous groups of numbers.

We keep two indices:

i - the position of the smallest number we keep
j - the position of the largest number we can still keep
For a fixed i, we want nums[j]≤nums[i]∗k.

Instead of starting j from i every time(like in the brute force solution), we notice something important:
When i moves to the right, nums[i] becomes larger, so
nums[i]∗k also becomes larger.
That means j will never need to move backward - it can only stay where it is or move forward.

Code
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, j = 0; i < n; i ++){
            while(j + 1 < n && (long long)nums[i] * k >= nums[j + 1]){
                j += 1;
            }
            ans = max(ans, j - i + 1);
        }
        return n - ans;
    }
};
Time complexity: O(N∗log(N))
Space complexity: O(1)

*/

