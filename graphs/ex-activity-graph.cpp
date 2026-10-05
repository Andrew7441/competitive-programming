// Graph course exercise — Activity Graph (remove activity API + simulate execution with start times)
// Statement: comment below
// Topic: graphs | Tags: topological-sort, dag, critical-path, design
// Complexity (yours): removeNode O((V + E) + log V), simulate O((V + E) log V)
#include<bits/stdc++.h>
using namespace std;

/*
1. Write the classes and their attributes representing such data-structure

2. Create an API that inputs an activity name and removes a node with a matching
name from the graph. An error will be issued if such node does not exist.

3. Provide an API that simulates an execution of the activity, printing the activity
node names in their order of execution, and the time they started to run.


          -> B(7) ----\
Start -> A(5)          -> End
          -> C(10) -> D(15) -/


*/


struct ActivityNode{
    string name;
    int duration;
    vector<string> outgoing;

    ActivityNode(string n, int d): name{n}, duration{d} {}
};

class ActivityGraph{
private:
    map<string, ActivityNode> nodes;
public:
    void addNode(const string& name, int duration){
        if(nodes.count(name)) throw runtime_error("Node already exists" + name);
        nodes.emplace(name, ActivityNode(name, duration));
    }

    void addEdge(const string& from , const string& to){
        if(!nodes.count(from) || !nodes.count(to)) throw runtime_error("Both nodes should exist");
        
        vector<string>& out = nodes.at(from).outgoing;
        
        if(find(out.begin(), out.end(), to) == out.end()){
            out.push_back(to);
        }
    }

    void removeNode(const string& name){
        if(!nodes.count(name)) throw runtime_error("Node doesnt exist");

        nodes.erase(name);

        for(auto& [nodeName, node] : nodes){
            auto& out = node.outgoing;
            out.erase(remove(out.begin(), out.end(), name), out.end());
        }
    }

    void simulate(){
        map<string, int> indegree;  // number of prerequisites each node has
        map<string, int> startTime; // earliest time each node can start

        //step 1: initialize every node
        for(auto& [name, node] : nodes){
            indegree[name] = 0;  // At First, assume no preReq
            startTime[name] = 0; //assume it can start at time 0
        }

        //step 2: count how many incoming edges each node has
        //ex A->B, B has one prereq
        for(auto& [name, node] : nodes){
            for(const string& next : node.outgoing){
                indegree[next]++;
            }
        }

        //step 3: store nodes that are ready to run
        //a node is ready when indegree = 0
        priority_queue<string, vector<string>, greater<string>> ready;

        for(auto& [name, deg] : indegree){
            if(deg == 0){
                ready.push(name);
            }
        }

        vector<string> executionOrder;

        //process ready nodes
        while(!ready.empty()){
            string current = ready.top();
            ready.pop();

            executionOrder.push_back(current);
            
            // Finish time = start time + duration
            int finishTime = startTime[current] + nodes.at(current).duration;

            // Visit all nodes that depend on current
            for (const string& next : nodes.at(current).outgoing) {
                // next cannot start until current finishes
                // If next has multiple prerequisites, take the latest finish time
                startTime[next] = max(startTime[next], finishTime);

                // One prerequisite of next is now completed
                indegree[next]--;

                // If all prerequisites are completed, next is ready to run
                if (indegree[next] == 0) {
                    ready.push(next);
                }
            }
        }
        // Step 5: If not all nodes were processed, there is a cycle
        // Example: A -> B -> A, impossible to execute
        if (executionOrder.size() != nodes.size()) {
            throw runtime_error("Cycle detected. Execution is impossible.");
        }

        map<string, int> rank;

        for(int i = 0; i < (int)executionOrder.size(); i++){
            rank[executionOrder[i]] = i;
        }

        // Step 6: Print nodes by the time they start running
        sort(executionOrder.begin(), executionOrder.end(),
            [&](const string& a, const string& b) {
                if (startTime[a] != startTime[b]) {
                    return startTime[a] < startTime[b];
                }
                return rank[a] < rank[b]; // Tie-breaker for same start time
        });

        for (const string& name : executionOrder) {
            cout << name << " starts at time " << startTime[name] << endl;
        }
    }
};

int main() {
    try {
        ActivityGraph graph;

        graph.addNode("Start", 0);
        graph.addNode("A", 5);
        graph.addNode("B", 7);
        graph.addNode("C", 10);
        graph.addNode("D", 15);
        graph.addNode("End", 0);

        graph.addEdge("Start", "A");
        graph.addEdge("A", "B");
        graph.addEdge("A", "C");
        graph.addEdge("C", "D");
        graph.addEdge("B", "End");
        graph.addEdge("D", "End");

        // graph.removeActivity("C"); // Example remove API

        graph.simulate();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

/*
Complexity

removeActivity() is O(V + E).

simulateExecution() is O((V + E) log V) because of the priority queue. Without deterministic ordering, it can be O(V + E) using a normal queue.

Interviewer questions they may ask
Why use topological sort?
Because activities depend on previous activities, so execution must respect dependency order.

What happens if the graph has a cycle?
Execution is impossible because some activity would wait forever. The code detects this.

Why does End start at time 30?
End waits for both B and D. B finishes at 12, D finishes at 30, so End starts at 30.

Can B and C run in parallel?
Yes. Both depend only on A, so both start at time 5.

What happens when removing a node?
The node is deleted, and all edges pointing to it are removed.

Would you reconnect the graph after deletion?
Only if the requirement says so. This implementation does not reconnect automatically.

Why store outgoing edges instead of incoming edges?
Outgoing edges make traversal and topological execution simple.

How would you optimize further?
Use unordered_map for faster average lookups and a normal queue if deterministic alphabetical ordering is not needed.
*/

/*
💭 First Idea: Kahn topological sort; each node's start time = max finish time of its predecessors; print nodes sorted by start time.
🧩 Key Property / Invariant: a node is popped only after all its predecessors are processed, so its startTime is final when popped.
✅ Key insight: earliest start = longest path from Start (critical path) — computed in one pass over a topological order.
🔁 Recognition cue for next time: "activities with dependencies / durations / when does each start" -> topological sort + DP on DAG.
⏱  Speed fix for next time: the commented call in main uses removeActivity() but the method is removeNode() — keep names consistent.
🛠  Review: correct (prints Start 0, A 0, B 5, C 5, D 15, End 30); Already optimal.
*/
