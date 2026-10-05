// Codeforces 271A — Beautiful Year
// https://codeforces.com/problemset/problem/271/A
// Topic: brute-force | Tags: math
// Complexity (yours): O(k) time where k = gap to next answer (small), O(1) space

#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/271/A A. Beautiful Year


int main() {

    int y;
    cin >> y;

    
    while(true){
        y++;
        int temp = y;
        unordered_set<int> r;
        
        while(temp>0){
            r.insert(temp%10);
            temp/=10;
        }
        
        if(r.size()==4){
            cout << y;
            break;
        }
    }

    return 0;
}

/*
💭 First Idea: Increment the year until all 4 digits are distinct.
🧩 Key Property / Invariant: Answer always exists below 9012 and is close, so brute force is fast.
✅ Key insight: Check distinct digits with a set of the 4 digits.
🔁 Recognition cue for next time: 'Next number with digit property' and small range -> just try them.
⏱  Speed fix for next time: Use a bool seen[10] instead of creating an unordered_set each time.
🛠  Review: correct; Already optimal.
*/
