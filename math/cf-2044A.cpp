// Codeforces 2044A — Easy Problem
// https://codeforces.com/problemset/problem/2044/A
// Topic: math
// Complexity (yours): O(1) per test
#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << n - 1 << "\n";
    }

    return 0;
}







// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while(t--){
//         int a;
//         cin >> a;

//         int res = 0;

//         for(int i = 0; i < a; i++){
//             for(int j = 0; j < a; j++){
//                 if(i == a - j){
//                     res++;
//                 }
//             }
//         }

//         cout << res << "\n";
//     }

//     return 0;
// }

/*
💭 First Idea: Answer is n - 1 (pairs (a, b) with a = n - b, a, b >= 1).
🧩 Key Property / Invariant: b ranges 1..n-1 and determines a.
✅ Key insight: Count of positive solutions of a + b = n is n - 1.
🔁 Recognition cue for next time: "Count ordered pairs with a = n - b" -> one free variable.
⏱  Speed fix for next time: Skip brute force loops for counting formulas; try n = 2, 3, 4.
🛠  Review: correct; Already optimal.
*/
