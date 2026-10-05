// Practice — Fibonacci (nth Number)
// Topic: dynamic-programming | Tags: math, recursion
// Complexity (yours): RFib O(2^n); MFib O(n) time/space; Ifib O(n) time, O(1) space
// Source: split from codeforces/practice.cpp (original problem statement below)
// Fibonacci (nth Number)
//
// Write a function that returns the nth Fibonacci number. The sequence starts: 0, 1, 1, 2, 3, 5, 8, 13, ...
// Example: fibonacci(6) → 8 (0-indexed: F(0)=0, F(1)=1, ..., F(6)=8)

#include <bits/stdc++.h>
using namespace std;

//Naive recursion - O(2^n) tc
int RFib(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;

    return RFib(n - 1) + RFib(n - 2);
}

//memoized recursion - O(n) tc, O(n) sc
int MFib(int n, vector<int>& memo){
    if(n <= 0) return 0;
    if(n == 1) return 1;

    if(memo[n] != -1) return memo[n];

    memo[n] = MFib(n-1, memo) + MFib(n-2, memo);

    return memo[n];
}


//Iterative - O(n) tc , O(1) sc
int Ifib(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;

    int num1 = 0, num2 = 1;

    for(int i = 2; i <= n; i++){
        int cur = num1 + num2;
        num1 = num2;
        num2 = cur;
    }

    return num2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << Ifib(6);
    cout << RFib(6);

    vector<int> memo(6, -1);

    return 0;
}

/*
💭 First Idea: Three versions: naive recursion, memoized recursion, iterative two-variable DP.
🧩 Key Property / Invariant: F(n) depends only on F(n-1) and F(n-2).
✅ Key insight: Keeping only the last two values gives O(n) time and O(1) space; matrix power / fast doubling gives O(log n).
🔁 Recognition cue for next time: "Each term from the previous k terms" -> rolling DP variables.
⏱  Speed fix for next time: memo must have size n + 1 (main allocates memo(6) for n = 6, which would be out of bounds if MFib(6) were called).
🛠  Review: correct; Ifib O(n) -> Already optimal for this task (use long long beyond F(46)).
*/
