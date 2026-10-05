// LeetCode 1390 — Four Divisors
// https://leetcode.com/problems/four-divisors/
// Topic: math | Tags: number-theory, arrays
// Complexity (yours): O(n·√M) time, O(1) space
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

/*
💭 First Idea: Trial division up to √num; stop early once a second divisor pair or a square root appears.
🧩 Key Property / Invariant: A number has exactly 4 divisors iff it has exactly one pair (i, num/i) with 1 < i < num/i (forms p*q or p^3).
✅ Key insight: Count divisors in pairs; a perfect-square divisor means an odd count, so it can never be 4.
🔁 Recognition cue for next time: "count/sum divisors of each element" with values <= 1e5 -> √M trial division (or a divisor sieve).
⏱  Speed fix for next time: Break as soon as count > 2; that already keeps the inner loop short.
🛠  Review: correct (stress-tested vs brute force); O(n√M) -> Already optimal for these limits.
*/
