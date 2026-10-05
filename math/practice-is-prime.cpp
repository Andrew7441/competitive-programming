// Practice — Check if a Number is Prime
// Topic: math | Tags: brute-force
// Complexity (yours): O(sqrt x) time, O(1) space
// Source: split from codeforces/practice.cpp (original problem statement below)
// Check if a Number is Prime
//
// Write a function that returns true if a given number is prime, false otherwise.
// Example: is_prime(7) → true, is_prime(12) → false

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x){
    if(x < 2) return false;

    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }

    return true;
}


int main(){
    cout << boolalpha;
    cout << is_prime(31);

    return 0;
}

/*
💭 First Idea: Trial division by every i with i * i <= x.
🧩 Key Property / Invariant: A composite x has a divisor <= sqrt(x).
✅ Key insight: Checking up to sqrt(x) is enough; skipping even i after 2 halves the work.
🔁 Recognition cue for next time: "Is x prime" for a single x <= 1e12-ish -> trial division to sqrt(x); many queries -> sieve.
⏱  Speed fix for next time: Write the condition as i <= x / i (or use long long) so i * i cannot overflow for x near INT_MAX.
🛠  Review: correct; O(sqrt x) -> Already optimal for one query (minor: i * i overflows int only for primes near 2^31).
*/
