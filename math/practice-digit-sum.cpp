// Practice — Sum of Digits
// Topic: math | Tags: strings
// Complexity (yours): O(d) time, O(d) space (d = number of digits)
// Source: split from codeforces/practice.cpp (original problem statement below)
// Given a positive integer, return the
// sum of its digits. Input:  1234

#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    string s = to_string(n);
    int sum = 0;

    for(char& c : s){
        sum += c - '0';
    }

    return sum;
}

int main(){

    cout << solve(1234);

    return 0;
}

/*
💭 First Idea: Convert to string and add c - '0' for every character.
🧩 Key Property / Invariant: Each decimal digit contributes its own value independently.
✅ Key insight: Either iterate the string or use n % 10 / n /= 10 without extra memory.
🔁 Recognition cue for next time: "Sum/product/count of digits" -> peel digits with % 10.
⏱  Speed fix for next time: Arithmetic loop: while (n) { sum += n % 10; n /= 10; } avoids the string.
🛠  Review: correct; O(d) -> Already optimal (string version uses O(d) extra space, fine).
*/
