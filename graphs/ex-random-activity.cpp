// Graph course exercise — Random Activity Diagram with an exact execution time
// Statement: comment below
// Topic: graphs | Tags: dag, longest-path, randomized, constructive
// Complexity (yours): create O(K) (K <= maxNodes), executionTime O(V + E) (memoized longest path)
#include <bits/stdc++.h>
using namespace std;

/*
Write a function that inputs a number and creates a new random activity-diagram in
which the execution time is equal exactly to the given number

------          ------
start |         |end |
------          ------
       
*/

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

// ===================== ⚡ Optimized =====================
// Same idea, but the diagram is a real random DAG, not always a single chain:
// build the critical chain (sum = totalTime), then add extra parallel activities that
// hang between chain node i and chain node j and fit inside the slack start[j] - finish[i],
// so they never lengthen the critical path. Verify with executionTime().
// To submit: call optimized::create instead of create.
namespace optimized {
ActivityDiagram create(int totalTime, int maxNodes = 10, int extraNodes = 5){
    if(totalTime <= 0 || maxNodes <= 0) throw invalid_argument("should be positive");
    mt19937 rng(random_device{}());
    auto rnd = [&](int lo, int hi){ return uniform_int_distribution<int>(lo, hi)(rng); };

    int k = rnd(1, min(totalTime, maxNodes));        // chain activities
    vector<int> dur(k);
    int remaining = totalTime;
    for(int i = 0; i < k - 1; i++){
        dur[i] = rnd(1, remaining - (k - i - 1));
        remaining -= dur[i];
    }
    dur[k - 1] = remaining;

    ActivityDiagram d;
    d.nodes.push_back({"Start", 0, {}});
    vector<int> chain = {0}, st = {0}, fin = {0};    // chain node ids + their start/finish times
    for(int i = 0; i < k; i++){
        int id = d.nodes.size();
        d.nodes.push_back({"Activity_" + to_string(i + 1), dur[i], {}});
        d.nodes[chain.back()].next.push_back(id);
        st.push_back(fin.back());
        fin.push_back(fin.back() + dur[i]);
        chain.push_back(id);
    }
    int endId = d.nodes.size();
    d.nodes.push_back({"End", 0, {}});
    d.nodes[chain.back()].next.push_back(endId);
    chain.push_back(endId); st.push_back(totalTime); fin.push_back(totalTime);

    for(int e = 0; e < extraNodes; e++){
        int i = rnd(0, (int)chain.size() - 2), j = rnd(i + 1, (int)chain.size() - 1);
        int slack = st[j] - fin[i];
        if(slack < 1) continue;                      // no room for a parallel activity here
        int id = d.nodes.size();
        d.nodes.push_back({"Parallel_" + to_string(e + 1), rnd(1, slack), {}});
        d.nodes[chain[i]].next.push_back(id);
        d.nodes[id].next.push_back(chain[j]);
    }
    return d;                                        // executionTime(d) == totalTime
}
}

/*
💭 First Idea: split totalTime into K random positive durations and chain Start -> A1 -> ... -> AK -> End.
🧩 Key Property / Invariant: execution time of an activity diagram = longest (critical) path from Start to End.
✅ Key insight: fix the critical path to sum exactly to T; anything added in parallel must fit inside the slack, so the longest path stays T.
🔁 Recognition cue for next time: "generate a random structure with an exact property" -> build a skeleton that guarantees it, then add random parts that can't break it.
⏱  Speed fix for next time: reuse one static RNG; the random-split (stars and bars) loop is already O(K).
🛠  Review: correct (chain always has execution time T, checked for many T); yours O(K) → optimized O(K + extra), adds real branching.
*/
