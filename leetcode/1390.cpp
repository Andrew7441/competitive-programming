#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;

        for(int num : nums){
            int sum = 0;
            int count = 0;
            for(int i = 2; i * i <= num; i++){
                if(num % i == 0){
                    int j = num / i;

                    if(i == j){
                        count = 5;
                        break;
                    }

                    count+=2;
                    sum += i + j;

                    if(count > 2) break;
                }
            }
            if(count == 2){
                res += sum + 1 + num;
            }
        }
        return res; 
    }
};

int main() {
    vector<int> nums = {21,4,7};

    Solution S;
    cout << S.sumFourDivisors(nums);
    
}