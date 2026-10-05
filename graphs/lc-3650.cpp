// LeetCode 3650 — Minimum Cost Path with Edge Reversals
// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/
// Topic: graphs | Tags: shortest-path, dijkstra, heap
// Complexity (yours): O((n + m) log m) time, O(n + m) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], 2 * it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            if(distance > dist[node])
                continue;
            
            if(node == n - 1)
                return distance;
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                int weight = it.second;
                if(distance + weight < dist[adjnode]){
                    dist[adjnode] = distance + weight;
                    pq.push({distance + weight, adjnode});
                }
            }
        }
        return -1;
    }
};


int main() {
    vector<vector<int>> edges{{0,2,1},{2,1,1},{1,3,1},{2,3,3}};

    Solution S;

    cout << S.minCost(4, edges);
}


/*
Intuition:
Ill be using Dijkstra algorithm 

In the cases that i will be applying the mentioned operation(reverse/Switch)
    First Scenario, i need to make a switch when no path exists to n-1 node.
    Second Scenario, when i get a minimum path when switching compared to a longer path.

*/
/*
💭 First Idea: Dijkstra where every edge u->v (w) also gives a reverse edge v->u with cost 2w.
🧩 Key Property / Invariant: Each node's switch is used at most once and only to leave that node, so it is just an extra edge of cost 2w.
✅ Key insight: The one-time reversal never needs to be tracked in state because a shortest path visits each node once.
🔁 Recognition cue for next time: "Optional per-node move with a cost" -> model it as extra weighted edges, then plain Dijkstra.
⏱  Speed fix for next time: Iterate edges by const reference (auto& it) to avoid copying vectors.
🛠  Review: correct; Already optimal (max dist 2*1000*5e4 fits int).
*/
