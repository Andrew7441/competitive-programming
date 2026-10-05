// Codeforces 1900C — Anji's Binary Tree
// https://codeforces.com/problemset/problem/1900/C
// Topic: trees | Tags: dfs, dynamic-programming
// Complexity (yours): O(n) time, O(n) space (recursion depth up to n)
#include <bits/stdc++.h>
using namespace std;

/*https://codeforces.com/problemset/problem/1900/C*/

void dfs(int node, int changes, string& s, vector<int>& leftChild, vector<int>& rightChild, int& answer){
    
    //leaf Node    
    if(leftChild[node] == 0 && rightChild[node] == 0){
        answer = min(answer, changes);
        return;
    }

    //move to left child
    if(leftChild[node] != 0){
        int cost = (s[node - 1] == 'L') ? 0 : 1;
        dfs(leftChild[node], changes + cost, s, leftChild, rightChild, answer);
    }

    //move to right child
    if(rightChild[node] != 0){
        int cost = (s[node - 1] == 'R') ? 0 : 1;
        dfs(rightChild[node], changes + cost, s, leftChild, rightChild, answer);
    }
}

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> leftChild(n + 1), rightChild(n + 1);
    int answer = INT_MAX;

    for(int i = 1; i <= n; i++){
        cin >> leftChild[i] >> rightChild[i];
    }
    
    dfs(1, 0, s, leftChild, rightChild, answer);
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

/*
💭 First Idea: DFS from the root carrying the number of letter changes; take the min at leaves.
🧩 Key Property / Invariant: Going to child c from v costs 1 iff s[v] doesn't already point to c.
✅ Key insight: Min-cost root-to-leaf path in a tree = one DFS with accumulated cost.
🔁 Recognition cue for next time: 'Change minimum letters so a walk reaches a leaf' -> root-to-leaf path cost.
⏱  Speed fix for next time: Recursion depth up to 3*10^5 is fine on CF; use an explicit stack if running locally.
🛠  Review: correct; Already optimal.
*/
