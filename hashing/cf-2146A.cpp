// Codeforces 2146A — Equal Occurrences
// https://codeforces.com/problemset/problem/2146/A
// Topic: hashing | Tags: brute-force, sorting
// Complexity (yours): O(n^2) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        std::map<int, int> m;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            m[x]++;
        }

        vector<int> counts;
        for(auto &p : m) counts.push_back(p.second);

        sort(counts.begin(), counts.end());

        int maxLen = 0;
        for(int k = 1; k <= n; k++){
            int num = 0;
            for(int c : counts){
                if(c >= k) num++;
            }
            maxLen = max(maxLen, num * k);
        }
        cout << maxLen << '\n';
    }

    return 0;
}

/*
💭 First Idea: Count frequencies; for each target count k use every value with freq >= k, answer = max k * #values.
🧩 Key Property / Invariant: In a balanced subsequence every chosen value appears the same k times; values with freq >= k can give exactly k.
✅ Key insight: Try every k in 1..n and keep the best k * count(freq >= k).
🔁 Recognition cue for next time: "All chosen elements appear equally often" -> enumerate the common frequency.
⏱  Speed fix for next time: Sort frequencies descending: answer = max f[i] * (i+1), O(n log n) (not needed for n <= 100).
🛠  Review: correct; O(n^2) -> fine for n <= 100 (O(n log n) possible, not worth extra code).
*/
