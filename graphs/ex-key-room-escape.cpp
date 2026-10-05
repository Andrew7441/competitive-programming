// Graph course exercise — Key-Room Escape Graph (reach Exit collecting keys)
// Statement: comment below (graph course sheet: graphs/ex-questions.md)
// Topic: graphs | Tags: bfs, state-space-search, bitmask
// Complexity (yours): — (stub)
// ⚠️ Review: unfinished — solve() is empty and main does nothing; see corrected version below.
#include <bits/stdc++.h>
using namespace std;

/*
Given a graph representing rooms in a locked building.

Each room may contain one key.
Each directed door may require one key to pass through.
The player starts with no keys, but collects keys automatically when entering rooms.

1. Write the classes and their attributes representing:
   - Room
   - Door
   - BuildingGraph

2. Given a start room and an exit room, determine whether the player can reach the exit.

Rules:
- Doors are directed.
- A door with requiredKey = ' ' is open.
- The player may revisit rooms.
- If the player reaches the exit, print YES, otherwise print NO.

EX:

(Entrance) --open--> (Hall: key=A) --A--> (Lab)
     |
   open
     v
(Storage: key=B) --open--> (Hall)

(Lab) --B--> (Exit)

Question:
Can the player reach Exit from Entrance?
*/



void solve(){
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

// ===================== ⚡ Optimized =====================
// BFS over states (room, set of keys held) — O(2^K * (R + D)) with K = distinct keys.
// Keys are never lost, but doors are directed, so a key in a dead-end room may be useless:
// the key set must be part of the state (a global "all keys seen" set would be wrong).
// To submit: call optimized::solve() from main.
namespace optimized {
struct Room { string name; char key; };          // key == ' ' -> no key in this room
struct Door { int from, to; char requiredKey; };  // requiredKey == ' ' -> open door

class BuildingGraph {
    vector<Room> rooms;
    vector<vector<Door>> out;                     // out[r] = doors leaving room r
    unordered_map<string, int> id;
    unordered_map<char, int> keyBit;              // key char -> bit index

    int bit(char k){
        if(k == ' ') return -1;
        auto it = keyBit.find(k);
        if(it != keyBit.end()) return it->second;
        int b = keyBit.size();
        keyBit[k] = b;
        return b;
    }
public:
    void addRoom(const string& name, char key = ' '){
        if(id.count(name)) throw runtime_error("Room already exists: " + name);
        id[name] = rooms.size();
        rooms.push_back({name, key});
        out.emplace_back();
        bit(key);
    }
    void addDoor(const string& from, const string& to, char requiredKey = ' '){
        if(!id.count(from) || !id.count(to)) throw runtime_error("Both rooms should exist");
        out[id[from]].push_back({id[from], id[to], requiredKey});
        bit(requiredKey);
    }
    bool canReach(const string& start, const string& exitRoom){
        if(!id.count(start) || !id.count(exitRoom)) return false;
        auto keyMask = [&](int r){ int b = bit(rooms[r].key); return b < 0 ? 0 : 1 << b; };
        int s = id[start], t = id[exitRoom];
        vector<unordered_set<int>> seen(rooms.size());
        queue<pair<int,int>> q;                   // (room, keys held)
        int m0 = keyMask(s);                      // key in the start room is picked up immediately
        seen[s].insert(m0);
        q.push({s, m0});
        while(!q.empty()){
            auto [r, mask] = q.front(); q.pop();
            if(r == t) return true;
            for(const Door& d : out[r]){
                int need = bit(d.requiredKey);
                if(need >= 0 && !(mask >> need & 1)) continue;   // locked and we lack the key
                int nm = mask | keyMask(d.to);
                if(seen[d.to].insert(nm).second) q.push({d.to, nm});
            }
        }
        return false;
    }
};

void solve(){
    BuildingGraph g;
    g.addRoom("Entrance");
    g.addRoom("Hall", 'A');
    g.addRoom("Lab");
    g.addRoom("Storage", 'B');
    g.addRoom("Exit");
    g.addDoor("Entrance", "Hall");
    g.addDoor("Entrance", "Storage");
    g.addDoor("Hall", "Lab", 'A');
    g.addDoor("Storage", "Hall");
    g.addDoor("Lab", "Exit", 'B');
    cout << (g.canReach("Entrance", "Exit") ? "YES" : "NO") << "\n";   // YES: Entrance->Storage(B)->Hall(A)->Lab->Exit
}
}

/*
💭 First Idea: (stub) — natural first idea: BFS/DFS from Entrance, only passing doors whose key you hold.
🧩 Key Property / Invariant: keys are only ever gained, so the full state is (room, set of keys); revisiting a room only helps with a NEW key set.
✅ Key insight: BFS on the product graph (room x keyMask); doors are directed, so a global "all keys seen" set is wrong (dead-end key rooms).
🔁 Recognition cue for next time: "reach target, collecting items that unlock edges" -> BFS over (node, bitmask of items).
⏱  Speed fix for next time: map key chars to bit indices once; visited = per-room set (or array) of masks.
🛠  Review: unfinished (empty stub); optimized BFS over (room, keyMask) O(2^K * (R + D)).
*/
