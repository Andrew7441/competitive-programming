// Graph course exercise — Word Matching Graph (is a word accepted?)
// Statement: comment below
// Topic: graphs | Tags: dfs, automaton (NFA), backtracking
// Complexity (yours): worst case O(d^L) (d = out-degree, L = |word|; no memo) + O(L) string copy per call
// ⚠️ Review: main() omits the a->a self-loop (↺ in the diagram), so "aabc" prints NO; see corrected version below.
#include<bits/stdc++.h>
using namespace std;

/*

Given a graph representing word matching process
Given a specific word, the graph will determine whether the word is accepted or rejected

1. Write the classes and their attributes representing such graph
2. Given a word, determine whether it is accepted by a word matching graph

EX:
                          ________
               ↺         ▽        \
(Start) ────> (a) ────> (b) ────> (c) ────> (End)
                \                ^ 
                \______________/

*/


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

// ===================== ⚡ Optimized =====================
// O(L * E) instead of exponential: memoize failed (node, index) states, pass word by const&.
// Also builds the example with the a->a self-loop from the diagram.
// To submit: call optimized::solve() from main.
namespace optimized {
bool dfs(Node* node, const string& word, int index, set<pair<Node*,int>>& dead){
    if(index == (int)word.size()){
        for(Node* next : node->nodes) if(next->isEnd) return true;
        return false;
    }
    if(dead.count({node, index})) return false;      // already proved this state fails
    for(Node* next : node->nodes){
        if(next->value == word[index] && dfs(next, word, index + 1, dead)) return true;
    }
    dead.insert({node, index});
    return false;
}

bool isAccepted(Node* start, const string& word){
    set<pair<Node*,int>> dead;
    return dfs(start, word, 0, dead);
}

void solve(){
    Node start(' '), a('a'), b('b'), c('c'), end(' ', true);
    start.nodes = {&a};
    a.nodes = {&a, &b, &c};      // a->a self-loop (↺), a->b, a->c
    b.nodes = {&c};
    c.nodes = {&b, &end};
    string word;
    cin >> word;
    cout << (isAccepted(&start, word) ? "YES" : "NO");
}
}

/*
💭 First Idea: model the matcher as a graph of character nodes and DFS from Start, consuming one char per edge; accept if End is adjacent when the word is used up.
🧩 Key Property / Invariant: state = (current node, how many chars consumed); the word is accepted iff (some node, L) with an edge to End is reachable.
✅ Key insight: it's an NFA walk — memoizing dead (node, index) states turns exponential backtracking into O(L * E).
🔁 Recognition cue for next time: "graph/automaton accepts a string?" -> BFS/DFS over (node, position) product states.
⏱  Speed fix for next time: pass strings by const&; encode every arrow of the diagram (self-loops are easy to miss).
🛠  Review: algorithm correct but example graph misses the a->a self-loop ("aabc" -> NO); yours exponential worst case → optimized O(L * E).
*/
