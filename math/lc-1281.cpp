// LeetCode 1281 — Subtract the Product and Sum of Digits of an Integer
// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Topic: math | Tags: strings
// Complexity (yours): O(d) time, O(d) space (d = number of digits)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        int prod = 1, sum = 0;

        for(char i : s){
            prod *= i - '0';
            sum += i - '0';
        }
        return prod - sum; 
    }
};

int main() {
    Solution Sol;

    cout << Sol.subtractProductAndSum(4421) << endl;
    
}

/*
💭 First Idea: Convert to string, accumulate the product and sum of the digits.
🧩 Key Property / Invariant: Each digit is visited once; product of at most 6 digits of 9 fits in int.
✅ Key insight: Use n % 10 and n /= 10 to get digits without a string (O(1) extra space).
🔁 Recognition cue for next time: "digits of an integer" -> % 10 / / 10 loop.
⏱  Speed fix for next time: Small enough to code straight away.
🛠  Review: correct; O(d) -> Already optimal.
*/
