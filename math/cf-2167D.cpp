// Codeforces 2167D — Yet Another Array Problem
// https://codeforces.com/problemset/problem/2167/D
// Topic: math | Tags: number theory, brute-force
// Complexity (yours): O(16 n) time, O(n) space
// Note: File was named 2176D but the code solves CF 2167D (Yet Another Array Problem); 2176D is Fibonacci Paths. Correct, already optimal.
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<long long> a(n);
    for(long long &x : a) cin >> x;

    vector<int> primes = {
        2, 3, 5, 7, 11, 13, 17, 19,
        23, 29, 31, 37, 41, 43, 47, 53
    };

    for(int p : primes){
        bool works = false;

        for(long long x : a){
            if(x % p != 0){
                works = true;
                break;
            }
        }

        if(works){
            cout << p << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

/*
💭 First Idea: Try primes 2..53; the first prime that fails to divide some a_i is the answer.
🧩 Key Property / Invariant: The smallest x coprime to some a_i is always prime (a prime factor of x works too and is smaller).
✅ Key insight: Product of primes <= 53 exceeds 1e18, so some prime <= 53 misses some a_i -> answer <= 53, never -1.
🔁 Recognition cue for next time: "Smallest x with gcd(x, a_i) = 1" -> answer is a small prime; bound with the primorial vs the value limit.
⏱  Speed fix for next time: Spot the primorial bound right away; the -1 case is a red herring.
🛠  Review: correct; O(16 n) -> Already optimal.
*/
