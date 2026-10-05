// Codeforces 158A — Next Round
// https://codeforces.com/problemset/problem/158/A
// Topic: implementation | Tags: arrays
// Complexity (yours): O(n) time, O(n) space
#include <iostream>
#include<vector>
using namespace std;

//https://codeforces.com/problemset/problem/158/A 


int main() {

    int n , k;
    cin >> n >> k;

    vector<int> pos(n); 

    for(int i = 0; i < n; i++){
        cin >> pos[i];
    }

    int threshold = pos[k - 1];
    int res = 0; 

    for(int score : pos){
        if(score >= threshold && score > 0){
            res++;
        }
    }
    
    cout << res;

    return 0;
}

/*
💭 First Idea: Threshold = k-th score; count scores >= threshold and > 0.
🧩 Key Property / Invariant: Scores are non-increasing, so the k-th score is the cutoff.
✅ Key insight: Don't forget the positive-score condition.
🔁 Recognition cue for next time: 'Advance if >= k-th place' -> compare with a[k-1].
⏱  Speed fix for next time: Check the all-zero sample.
🛠  Review: correct; Already optimal.
*/
