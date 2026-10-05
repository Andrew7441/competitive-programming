// Codeforces 1703A — YES or YES?
// https://codeforces.com/problemset/problem/1703/A
// Topic: strings
// Complexity (yours): O(1) time, O(1) space
#include <iostream>
#include<string>

using namespace std;

//https://codeforces.com/problemset/problem/1703/A

int main() {

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        string s; 
        cin >> s;
        for(char &i : s){
            i = tolower(i);
        }
        if(s == "yes"){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

/*
💭 First Idea: Lowercase the string and compare to "yes".
🧩 Key Property / Invariant: Case-insensitive compare = normalize case first.
✅ Key insight: tolower each char, then equality.
🔁 Recognition cue for next time: 'Any case allowed' -> normalize to one case.
⏱  Speed fix for next time: Inner loop variable 'i' shadows the outer 'i' - legal but rename to c.
🛠  Review: correct; Already optimal.
*/
