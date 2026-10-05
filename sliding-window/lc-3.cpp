// LeetCode 3 — Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Topic: sliding-window | Tags: hashing, strings, two-pointers
// Complexity (yours): O(n log σ) time, O(σ) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0, left = 0;
        set<char> st;

        for(int right = 0; right < s.length(); right++){
            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};

int main() {
    
    Solution S;

    cout << S.lengthOfLongestSubstring("abcabcbb");
}

// ===================== ⚡ Optimized =====================
// O(n), no inner loop: remember last index of each char and jump left past it.
class SolutionOptimized {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int best = 0, left = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            unsigned char c = s[r];
            if (last[c] >= left) left = last[c] + 1;  // repeat inside window -> jump
            last[c] = r;
            best = max(best, r - left + 1);
        }
        return best;
    }
};

/*
💭 First Idea: Sliding window; std::set holds window chars, shrink left one by one while s[right] is already inside.
🧩 Key Property / Invariant: Window [left, right] always has all-distinct chars; left never moves backwards.
✅ Key insight: Store the last index of each char and jump left straight to last[c] + 1 — no inner erase loop.
🔁 Recognition cue for next time: "Longest substring/subarray with no repeats / at most k distinct" → variable-size sliding window.
⏱  Speed fix for next time: int last[256] instead of set<char>: O(1) per step and less code.
🛠  Review: correct; yours O(n log σ) → optimized O(n) with a last-index array.
*/
