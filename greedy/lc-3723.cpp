#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/?envType=daily-question&envId=2026-10-14
*/

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // edge case where num = 1 and sum = 10
        if(num * 9 < sum) return "";

        string res = "";

        while(sum) {
            int digit = min(sum, 9);
            res += to_string(digit);
            sum -= digit;
        }   

        while((int)res.size() < num) {
            res += "0";
        }

        return res;
    }
};

int main() {
    Solution S;
    std::cout << S.maxSumOfSquares(2, 3) << '\n';
    return 0;
}

/*
💭 first idea
🧩 key property / invariant
✅ key insight
🔁 recognition cue for next time
⏱ speed fix for next time
*/