// Graph course exercise — Dynamic Word Matching Graph (add/remove states & transitions, isAccepted)
// Statement: comment below
// Topic: graphs | Tags: design, hashing, automaton (DFA)
// Complexity (yours): add/remove O(1) avg, isAccepted O(L) avg
// ⚠️ Review: removeState leaves transitions into/out of the removed state, so words can still be accepted through it; see corrected version below.
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

// ===================== ⚡ Optimized =====================
// Fix: removeState also deletes every transition from/into the state (O(V + E) for that call);
// isAccepted/removeTransition use find() so they don't insert empty map entries.
// To submit: use optimized::graph instead of graph.
namespace optimized {
class graph{
    unordered_set<string> states;
    unordered_map<string, unordered_map<char, string>> transitions;
public:
    void addState(const string& name){ states.insert(name); }

    void removeState(const string& name){
        if(!states.erase(name)) return;
        transitions.erase(name);                         // outgoing
        for(auto& [from, out] : transitions){            // incoming
            for(auto it = out.begin(); it != out.end(); ){
                if(it->second == name) it = out.erase(it);
                else ++it;
            }
        }
    }

    void addTransition(const string& from, const string& to, char c){
        if(!states.count(from) || !states.count(to)) return;
        transitions[from][c] = to;                       // DFA: one target per (state, char)
    }

    void removeTransition(const string& from, const string& to, char c){
        auto it = transitions.find(from);
        if(it == transitions.end()) return;
        auto jt = it->second.find(c);
        if(jt != it->second.end() && jt->second == to) it->second.erase(jt);
    }

    bool isAccepted(const string& word) const{
        if(!states.count("start")) return false;
        string current = "start";
        for(char c : word){
            auto it = transitions.find(current);
            if(it == transitions.end()) return false;
            auto jt = it->second.find(c);
            if(jt == it->second.end()) return false;
            current = jt->second;
        }
        return current == "end" && states.count("end");
    }
};
}

/*
💭 First Idea: store states in a hash set and transitions as state -> (char -> next state); walk the word from "start" and accept iff it ends at "end".
🧩 Key Property / Invariant: every transition must connect two existing states — removing a state must remove all its edges.
✅ Key insight: a DFA lookup is just one hash-map hop per character, O(L).
🔁 Recognition cue for next time: "graph with add/remove node/edge APIs" -> deleting a node means deleting its incident edges too (both directions).
⏱  Speed fix for next time: use find() instead of operator[] in read-only paths; keep a reverse-edge index if removeState must be fast.
🛠  Review: wrong — removeState leaves dangling transitions; yours O(L) accept → optimized O(L) accept, O(V + E) removeState.
*/
