#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (int i : nums)
        {
            mp[i]++;
        }

        int max = INT_MIN;
        int ans = 1;

        for (auto &p : mp)
        {
            if (p.second > max)
            {
                max = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};
int main()
{
    Solution Sol;
    vector<int> nums = {2, 1, 2, 5, 3, 2};

    cout << Sol.repeatedNTimes(nums);

}