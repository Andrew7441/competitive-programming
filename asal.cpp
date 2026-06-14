#include <bits/stdc++.h>
using namespace std;

//=======================================================================================================================
/*
Dynamic Word Matching Graph
Given a word-matching graph, implement APIs:
addState(name), removeState(name), addTransition(from, to, char), removeTransition(from, to, char), and isAccepted(word).
*/
class graph{
    unordered_set<string> states;
    unordered_map<string, unordered_map<char, string>> transitions;
public:
    void addState(const string& name){
        if(states.count(name)) return;
        states.insert(name);
    }

    void removeState(const string& name){
        if(!states.count(name)) return;
        states.erase(name);
    }

    void addTransition(const string& from, const string& to, char c){
        if(!states.count(from) || !states.count(to)) return;
        transitions[from][c] = to;
    }
    void removeTransition(string from, string to, char c){
        if(transitions[from].count(c) && transitions[from][c] == to)
            transitions[from].erase(c);
    }

    bool isAccepted(string word){
        string current = "start";

        for(char& c : word){
            if(!transitions[current].count(c)) return false;

            current = transitions[current][c];
        }

        return current == "end";
    }
};

int main(){
    graph g;

    g.addState("start");
    g.addState("s1");
    g.addState("s2");
    g.addState("end");


    g.addTransition("start","s1", 'c');
    g.addTransition("s1","s2",'a');
    g.addTransition("s2","end",'t');

    if(g.isAccepted("car")) cout << "yes";
    else cout << "no";

    return 0;
}

//=======================================================================================================================
/*EXERCISE 
class Node{
public:
    char value;
    bool isEnd;
    vector<Node*> nodes;

    Node(char v, bool isEnd = false): value{v}, isEnd{isEnd} {}
};

class Graph{
public:
    Node* start;

    Graph(Node* start){
        this->start = start;
    }

    bool dfs(Node* node, string word, int index){
        if(index == (int)word.size()){
            for(Node* next : node->nodes){
                if(next->isEnd) return true;
            }
            return false;
        }


        for(Node* next : node->nodes){
            if(next->value == word[index]){
                if(dfs(next, word, index + 1)) return true;
            }
        }

        return false;
    }

    bool isAccepted(string word){
        return dfs(start, word, 0);
    }
};

int main(){
    Node start(' ');
    Node a('a');
    Node b('b');
    Node c('c');
    Node end(' ', true);

    start.nodes.push_back(&a);

    a.nodes.push_back(&b);
    a.nodes.push_back(&c);

    b.nodes.push_back(&c);

    c.nodes.push_back(&b);
    c.nodes.push_back(&end);

    Graph graph(&start);

    string word;
    cout << "Enter word: ";
    cin >> word;

    if(graph.isAccepted(word)) cout << "YES";
    else cout << "NO";

    return 0;
}
*/

//=======================================================================================================================
//EXERCISE 2
/*
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

//=====================================EXERCISE 3==================================================================================
/*
struct Node{
    string name;
    int duration;
    vector<int> next;
};

struct ActivityDiagram{
    vector<Node> nodes;
};

int executionTime(const ActivityDiagram& diagram){
    vector<int> memo(diagram.nodes.size(), -1);

    function<int(int)> dfs = [&](int current){
        if(memo[current] != -1) return memo[current];

        int bestTime = 0;

        for(int nxt : diagram.nodes[current].next){
            bestTime = max(bestTime, dfs(nxt));
        }

        memo[current] = diagram.nodes[current].duration + bestTime;
        return memo[current];
    };

    return dfs(0);
}

ActivityDiagram create(int totalTime, int maxNodes = 10){
    if(totalTime <= 0) throw invalid_argument("should be positive");
    if(maxNodes <= 0) throw invalid_argument("should be positive");

    random_device rd;
    mt19937_64 rng(rd());

    int NodeCount = uniform_int_distribution<int>(1, min(totalTime, maxNodes))(rng);

    vector<int> durations(NodeCount, -1);
    int remainingTime = totalTime;

    for(int i = 0; i < NodeCount - 1; i++){
        int maxDur = remainingTime - (NodeCount - i - 1);
        durations[i] = uniform_int_distribution<int>(1, maxDur)(rng);
        remainingTime -= durations[i];
    }

    durations[NodeCount - 1] = remainingTime;

    ActivityDiagram diagram;

    diagram.nodes.push_back({"Start", 0, {}});

    for(int i = 0; i < NodeCount; i++){
        diagram.nodes.push_back({
            "Activity_" + to_string(i + 1),
            durations[i],
            {}
        });
    }
    diagram.nodes.push_back({"End", 0, {}});

    for(int i = 0; i < (int)diagram.nodes.size() - 1; i++){
        diagram.nodes[i].next.push_back(i+1);
    }

    return diagram;
}


void print(const ActivityDiagram& diagram){
    for(int i = 0; i < (int)diagram.nodes.size(); i++){
        cout << diagram.nodes[i].name << " [time = " << diagram.nodes[i].duration << "] -> ";

        for(auto& nxt : diagram.nodes[i].next){
            cout << diagram.nodes[nxt].name << " ";
        }
        cout << endl;
    }
}

int main(){
    int totalTime;

    cout << "Enter target Time: ";
    cin >> totalTime;

    ActivityDiagram diagram = create(totalTime);

    int actualTime = executionTime(diagram);

    cout << "total Time: " << totalTime << endl;
    cout << "actual Time: " << actualTime << endl;

    print(diagram);

    return 0;
}
Follow up Questions
follow-up questions for this exact code/problem:

What does executionTime() calculate?
It calculates the longest path from Start to End. In the current linear graph, that equals the sum of all activity durations.
Why are you using DFS with memoization?
To avoid recalculating the execution time of the same node multiple times, especially if the graph has branching.
What does memo[current] store?
It stores the maximum remaining execution time starting from node current.
Why do you return dfs(0)?
Because node index 0 is "Start", so dfs(0) gives the total execution time from the start of the diagram.
What is the time complexity of executionTime()?
O(V + E), where V is the number of nodes and E is the number of edges.
What is the space complexity?
O(V) for the memo array, plus recursion stack. The graph itself uses O(V + E).
What happens if the graph has a cycle?
This code does not detect cycles. A cycle could cause infinite recursion or stack overflow. To fix it, use a visited state array: unvisited, visiting, visited.
Why is bestTime = max(bestTime, dfs(nxt)) used?
Because parallel branches can run at the same time, so total execution time depends on the longest branch, not the sum of all branches.

Why does the current generated graph always behave like a sum?
Because it is a chain:

Start -> Activity_1 -> Activity_2 -> ... -> End

There are no parallel branches.

Why do Start and End have duration 0?
They represent boundary points, not real activities.
Why use vector<int> next instead of vector<Node*>?
Indices are simple, stable, and avoid pointer ownership issues.
What does this line do?
int NodeCount = uniform_int_distribution<int>(1, min(totalTime, maxNodes))(rng);

It randomly chooses the number of activity nodes between 1 and min(totalTime, maxNodes).

Why is NodeCount limited by totalTime?
Because every activity must have at least duration 1. You cannot split total time 7 into more than 7 positive activity durations.
Why do you subtract this?
int maxDur = remainingTime - (NodeCount - i - 1);

To leave at least 1 unit of duration for each remaining activity.

What does remainingTime represent?
The amount of total execution time that has not yet been assigned to activities.
Why do you set the last duration manually?
durations[NodeCount - 1] = remainingTime;

To guarantee all durations add up exactly to totalTime.

Can this generate a branching activity diagram?
No. This version only generates a linear chain.
How would you support branching?
Add edges from one activity to multiple next activities, while keeping the graph acyclic. Then execution time would be the longest path, not necessarily the sum.
Can different diagrams have the same total execution time?
Yes. For example:
Start -> A(7) -> End

and:

Start -> A(3) -> B(4) -> End

both have execution time 7.

What input values can break this code?
Negative or zero totalTime, negative or zero maxNodes, cycles if manually added, invalid edge indices, or very large values causing recursion depth issues.
*/