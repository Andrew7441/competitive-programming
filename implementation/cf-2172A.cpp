// Codeforces 2172A — ASCII Art Contest
// https://codeforces.com/problemset/problem/2172/A
// Topic: implementation | Tags: math
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/2172/A ASCII Art Contest

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g, c, l;
    cin >> g >> c >> l;

    int min = std::min({g, c, l});
    int max = std::max({g, c, l});

    if(max - min >= 10){
        cout << "check again"; 
    }else{
        int median = g + c + l - min - max; 
        cout << "final " << median;
    }

    
    
    return 0;
}

/*
💭 First Idea: min/max of the three scores; median = sum - min - max.
🧩 Key Property / Invariant: Median of three = total minus the two extremes.
✅ Key insight: max - min >= 10 -> 'check again', else 'final <median>'.
🔁 Recognition cue for next time: "Median of three numbers" -> sum - min - max.
⏱  Speed fix for next time: Avoid naming variables min/max (shadows std::min/std::max).
🛠  Review: correct; O(1) -> Already optimal.
*/
