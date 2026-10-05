// Practice — Power Without pow()
// Topic: math | Tags: bit-manipulation
// Complexity (yours): O(exp) time, O(1) space
// Source: split from codeforces/practice.cpp (original problem statement below)
// Write a function that calculates base raised to the power of exp without using ** or built-in power functions. 
// Assume exp is a non-negative integer. Input:  base = 2, exp = 10

#include <bits/stdc++.h>
using namespace std;

int solve(int base, int exp){
    int ans = 1;

    for(int i = 1; i <= exp; i++){
        ans *= base;
    }

    return ans;
}


int main(){

    cout << solve(2, 3);

    return 0;
}

// ===================== ⚡ Optimized =====================
// O(log exp) instead of O(exp): binary exponentiation (square the base, use the bits of exp).
namespace optimized {
long long solve(long long base, long long exp) {
    long long ans = 1;
    while (exp > 0) {
        if (exp & 1) ans *= base;
        base *= base;
        exp >>= 1;
    }
    return ans;
}
}

/*
💭 First Idea: Multiply ans by base exp times.
🧩 Key Property / Invariant: base^exp = (base^2)^(exp/2) * (base if exp is odd).
✅ Key insight: Binary exponentiation needs only O(log exp) multiplications.
🔁 Recognition cue for next time: "Compute a^b (often mod m) with large b" -> fast power.
⏱  Speed fix for next time: Memorize the 5-line binary exponentiation loop; use long long (or mod) to avoid overflow.
🛠  Review: correct for small inputs (main tests 2^3, not the stated 2^10); yours O(exp) -> optimized O(log exp).
*/
