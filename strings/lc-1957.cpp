// LeetCode 1957 — Delete Characters to Make Fancy String
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/
// Topic: strings | Tags: greedy
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        
        for(char c : s){
            int n = res.size();

            if(n < 2 || !(res[n-1] == c && res[n-2] == c)){
                res+=c;
            }
        }
        return res; 
    }
};

int main() {
    Solution Sol;

    cout << Sol.makeFancyString("leeetcode");

}

/*
💭 First Idea: Append each char unless the last two chars of the result already equal it.
🧩 Key Property / Invariant: The result must never have 3 equal in a row; keeping as many as possible is greedy-optimal.
✅ Key insight: Compare against the built result (not the input) so deletions are accounted for.
🔁 Recognition cue for next time: "no three consecutive equal characters" -> check the last two of the output.
⏱  Speed fix for next time: res.push_back on a std::string is amortised O(1); fine as is.
🛠  Review: correct; O(n) -> Already optimal.
*/
