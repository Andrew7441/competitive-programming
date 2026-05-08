#include <bits/stdc++.h>
using namespace std;

/**/

void BFS(vector<vector<int>> adj, int start){
    int n = adj.size();
    queue<int> q;
    vector<bool> visited(n, false);
    
    visited[0] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor: adj[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void DFS(vector<vector<int>> adj, int start, vector<bool>& visited){
    visited[start] = true;
    cout << start << " ";

    for(int neighbor : adj[start]){
        if(!visited[neighbor]){
            visited[neighbor] = true;
            DFS(adj, neighbor, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> adj(5);
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1};
    adj[4] = {2};

    BFS(adj, 0);
    cout << endl;

    int n = adj.size();
    vector<bool> visited(n, false);

    DFS(adj, 0, visited);


    return 0;
}

/*
💭 First Idea
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱  Speed fix for next time
*/