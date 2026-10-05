// Codeforces 80A — Panoramix's Prophecy
// https://codeforces.com/problemset/problem/80/A
// Topic: math | Tags: brute-force
// Complexity (yours): O(1) time, O(1) space
// ⚠️ Review: prints YES for any n < m (e.g. 7 9 -> YES, expected NO); never checks primes; see corrected version below.
#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/80/A
// brute force

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,m;
    cin >> n >> m;

    if(n > m){
        cout << "NO\n";
        return 0;
    }

    if(n % n == 0 and m % m == 0){
        cout << "YES\n";
    }


    return 0;
}

// ===================== ⚡ Optimized =====================
// Fix: actually check that m is prime AND no prime lies strictly between n and m.
// To submit: replace your main() body with optimized::solve().
namespace optimized {
bool isPrime(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0) return false;
    return true;
}
void solve() {
    int n, m;
    cin >> n >> m;
    int next = n + 1;
    while (!isPrime(next)) next++;   // next prime after n
    cout << (next == m ? "YES" : "NO") << "\n";
}
}

/*
💭 First Idea: Return NO if n > m, otherwise YES (n % n == 0 and m % m == 0 are always true).
🧩 Key Property / Invariant: m must be THE next prime after n: m is prime and nothing between n and m is prime.
✅ Key insight: Find next prime after n by trial division and compare with m.
🔁 Recognition cue for next time: 'Next prime' with values <= 50 -> trial division brute force.
⏱  Speed fix for next time: Test every sample - the 3rd sample (7 9 -> NO) fails this code.
🛠  Review: wrong because primality is never checked; fixed version O(m*sqrt m).
*/
