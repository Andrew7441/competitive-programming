// LeetCode 1598 — Crawler Log Folder
// https://leetcode.com/problems/crawler-log-folder/
// Topic: stack | Tags: implementation, strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;

        for(int i = 0; i < (int)logs.size(); i++){
            if(logs[i] == "./") continue;
            else if(logs[i] == "../"){
                if(res == 0) continue;
                else res--;
            }
            else res++;
        }
        return res; 
    }
};

int main() {
    Solution S;

    vector<string> logs{"d1/","d2/","../","d21/","./"};

    cout << S.minOperations(logs);
}

/*
💭 First Idea: Track the depth with a counter: '../' -> depth-- (not below 0), './' -> stay, otherwise depth++.
🧩 Key Property / Invariant: Only the depth matters, so a full stack of folder names can be replaced by its size.
✅ Key insight: The answer is the final depth (the number of '../' needed to get back to main).
🔁 Recognition cue for next time: "file system path navigation" -> stack, or just its size when names don't matter.
⏱  Speed fix for next time: Treat depth as a stack size; clamp at 0 for '../' at root.
🛠  Review: correct; O(n) -> Already optimal.
*/
