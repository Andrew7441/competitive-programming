// Codeforces 469A — I Wanna Be the Guy
// https://codeforces.com/problemset/problem/469/A
// Topic: hashing
// Complexity (yours): O(p + q) time, O(n) space
#include <bits/stdc++.h>
using namespace std;


int main() {

    int n; 
    cin >> n;

    int p;
    cin >> p;

    unordered_set<int> st1; 

    for(int i = 0; i < p; i++){
        int x; 
        cin >> x;
        st1.insert(x);
    }

    int q; 
    cin >> q;

    for(int i = 0; i < q; i++){
        int y;
        cin >> y; 
        st1.insert(y);
    }

    if(st1.size() == (size_t)n){
        cout << "I become the guy.\n";
    }else{
        cout << "Oh, my keyboard!\n";
    }

    return 0;
}

/*
💭 First Idea: Insert both players' levels into a set; check size == n.
🧩 Key Property / Invariant: Union of the two level lists must cover 1..n.
✅ Key insight: Set (or bool seen[n+1]) gives the union size.
🔁 Recognition cue for next time: 'Can together they cover everything' -> union via set.
⏱  Speed fix for next time: bool seen[101] is simpler and faster than unordered_set.
🛠  Review: correct; Already optimal.
*/
