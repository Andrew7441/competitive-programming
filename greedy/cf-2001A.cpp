// Codeforces 2001A — Make All Equal
// https://codeforces.com/problemset/problem/2001/A
// Topic: greedy | Tags: hashing, counting
// Complexity (yours): O(n) per test
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<int> freq(n + 1);
    for(int x : a) freq[x]++;

    cout << n - (*max_element(freq.begin(), freq.end())) << '\n';
  }
}

/*
💭 First Idea: Answer = n - (max frequency of any value).
🧩 Key Property / Invariant: Each operation deletes one element; keeping the most frequent value is always achievable.
✅ Key insight: Lower bound n - maxfreq is reachable since you can always delete a non-majority element next to a different one.
🔁 Recognition cue for next time: "Delete elements until all equal" -> keep the most frequent value.
⏱  Speed fix for next time: Frequency array + max_element.
🛠  Review: correct; Already optimal.
*/
