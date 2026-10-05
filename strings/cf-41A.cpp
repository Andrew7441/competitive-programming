// Codeforces 41A — Translation
// https://codeforces.com/problemset/problem/41/A
// Topic: strings | Tags: two-pointers
// Complexity (yours): O(n) time, O(1) space
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

//https://codeforces.com/problemset/problem/41/A Translation

int main() {

    
    string s, t; 
    cin >> s >> t;

    bool isequal = true; 

    for(size_t i = 0; i < s.length();i++){
        if(s[i] != t[t.length()-1-i] || s.length() != t.length()){
            isequal = false;
            break;
        }
    }

    

    if(isequal){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
}



/*
int main() {

    
    string s, t; 
    cin >> s >> t;

    std::reverse(t.begin(), t.end());

    if(s==t){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}
*/

/*
💭 First Idea: Compare s[i] with t[n-1-i] for every i (lengths must match).
🧩 Key Property / Invariant: t is the translation iff t == reverse(s).
✅ Key insight: Reverse one string and compare - or the commented std::reverse version.
🔁 Recognition cue for next time: 'Is word B word A backwards?' -> reverse + compare.
⏱  Speed fix for next time: Check the length mismatch once before the loop instead of each iteration.
🛠  Review: correct; Already optimal.
*/
