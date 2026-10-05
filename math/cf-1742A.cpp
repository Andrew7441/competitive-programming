// Codeforces 1742A — Sum
// https://codeforces.com/problemset/problem/1742/A
// Topic: math
// Complexity (yours): O(1) time, O(1) space
#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/1742/A Sum


int main() {

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a + b == c || a + c == b || b + c == a || b + a == c || c + a == b || c + b == a){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }



    return 0;
}

/*
💭 First Idea: Check every pair sum against the third number.
🧩 Key Property / Invariant: Only 3 distinct pairings exist (a+b=c, a+c=b, b+c=a); the other 3 checks are duplicates.
✅ Key insight: Sort the three: answer is YES iff x+y == z for the largest z.
🔁 Recognition cue for next time: Small fixed set -> sort then check.
⏱  Speed fix for next time: Drop the duplicate conditions.
🛠  Review: correct; Already optimal.
*/
