#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 0;

        if(n < 4) return false;    

        // strictly increasing 
        while(i + 1 < n && nums[i] < nums[i+1]) i++;
        if(i == 0) return false;
        int p = i;

        // strictly decreasing
        while(i + 1 < n && nums[i] > nums[i+1]) i++;
        if(i == p) return false;
        int q = i;

        //strictly increasing
        while(i + 1 < n && nums[i] < nums[i+1]) i++;
        

        return i == n - 1 && q < n - 1;
    }
};

int main() {
	vector<int> vec{1,3,5,4,2,6};
	Solution S;
	cout << boolalpha <<  S.isTrionic(vec) << "\n";
	return 0;
}

