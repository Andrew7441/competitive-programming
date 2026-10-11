#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/sum-of-squares-of-special-elements/description/?envType=daily-question&envId=2026-10-11
*/

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0)
                res += nums[i] * nums[i];
        }
        return res;
    }
};

int main() {
    std::vector<int> n{2,7,1,19,18,3};

    Solution S;
    std::cout << S.sumOfSquares(n) << '\n';
    
    return 0;
}

/*
💭 first idea
Iterate over all indices in the array. Question says what to do

🧩 key property / invariant
An element is special if n % (i + 1) == 0.

✅ key insight
Square and add nums[i] when its 1 based index divides n

🔁 recognition cue for next time
Use Modulo to check if one number divides the other

⏱ speed fix for next time
O(n) time, O(1) space. Already optimal.
*/