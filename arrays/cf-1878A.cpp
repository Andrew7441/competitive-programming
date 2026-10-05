// Codeforces 1878A — How Much Does Daytona Cost?
// https://codeforces.com/problemset/problem/1878/A
// Topic: arrays | Tags: implementation
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1878/A How Much Does Daytona Cost?

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int countk = 0;
        for(int x : a){
            if(x == k){
                countk++;
            }
        }

        if(countk == 0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }

    }


    return 0;
}

/*
💭 First Idea: Check whether k appears in the array.
🧩 Key Property / Invariant: A subsegment of length 1 [k] already has k as its most common element.
✅ Key insight: So the answer is YES iff k is present.
🔁 Recognition cue for next time: 'Exists a subsegment with property P' -> try the smallest subsegment first.
⏱  Speed fix for next time: No need to store the array or count - a bool flag is enough.
🛠  Review: correct; Already optimal.
*/
