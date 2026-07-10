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
