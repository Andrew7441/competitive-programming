// Codeforces 59A — Word
// https://codeforces.com/problemset/problem/59/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
#include<string>
#include <algorithm>

using namespace std;

//https://codeforces.com/problemset/problem/59/A word 

int main() {
    
    string s;  
    cin >> s; 

    int u = 0;
    int l = 0; 

    for(size_t i = 0; i < s.size();i++){
        if(s[i] <= 90 && s[i] >= 65){
            u++;
        }else if(s[i] <= 122 && s[i] >= 97){
            l++;
        }
    }

    if(u > l){
        std::transform(s.begin(),s.end(),s.begin(),[](unsigned char c){
            return toupper(c);
        });
    }else if(u < l || u == l){
        std::transform(s.begin(),s.end(),s.begin(),[](unsigned char c){
            return tolower(c);
        });
    }

    cout << s;

    return 0;
}

/*
💭 First Idea: Count upper/lower letters, convert whole word to the majority (tie -> lower).
🧩 Key Property / Invariant: Only the two counts matter.
✅ Key insight: Ties go to lowercase, so 'u > l' is the only upper case.
🔁 Recognition cue for next time: 'Change case by majority' -> count with isupper/islower.
⏱  Speed fix for next time: Use isupper()/islower() instead of ASCII numbers 65/90/97/122.
🛠  Review: correct; Already optimal.
*/
