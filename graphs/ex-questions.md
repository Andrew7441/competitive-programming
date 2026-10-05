
# Key-Room Escape Graph
Solution: ex-key-room-escape.cpp
/*
Given a graph representing rooms in a locked building.

Each room may contain one key.
Each directed door may require one key to pass through.

Starting from "Entrance", determine whether the player can reach "Exit".

1. Write the classes and their attributes representing:
   - Room
   - Door
   - BuildingGraph

2. Given the starting room, determine whether the exit is reachable.

Rules:
- Doors are directed.
- A door with requiredKey = ' ' is open.
- The player starts with no keys.
- The player automatically collects a room's key when entering that room.
- A key can only be used if it was collected earlier on the same path.
- The player may revisit rooms.
- If the player reaches the exit, print YES, otherwise print NO.

EX:

(Entrance) --open--> (Hall: key=A) --A--> (Lab)
     |
   open
     v
(Storage: key=B) --open--> (Hall)

(Lab) --B--> (Exit)

Expected output:
YES
*/

# Metro Station Graph
Solution: (none yet)

/*
Given a graph representing a metro system.

Each station is a node.
Each connection is an undirected weighted edge representing travel time.

1. Write the classes and their attributes representing:
   - Station
   - Connection
   - MetroGraph

2. Given a start station and destination station, return the minimum travel time.

Rules:
- All travel times are positive.
- If the destination cannot be reached, return -1.

EX:

Connections:
A --4-- B
A --10-- C
B --2-- C
B --3-- D
C --1-- D

Start = A
End = D

Expected output:
7
*/

# Course Prerequisite Graph
Solution: (none yet)

/*
Given a graph representing university course prerequisites.

Each course is a node.
A directed edge A -> B means course A must be completed before course B.

1. Write the classes and their attributes representing:
   - Course
   - CurriculumGraph

2. Given a list of completed courses, print all courses that can be taken now.

3. Detect whether the curriculum contains a cycle.

Rules:
- A course can be taken only if all of its prerequisites are completed.
- Already completed courses should not be printed.
- If the graph contains a cycle, print INVALID.

EX:

(Math1) ---> (Math2) ---> (Algorithms)
    |                         ^
    v                         |
(Programming1) ---------------

Completed:
Math1, Programming1

Expected output:
Math2
*/

# Package Conveyor Graph
Solution: (none yet)

/*
Given a graph representing an automatic package sorting system.

Each machine is a node.
Each directed edge has a condition.
A package starts at "Start" and follows matching edges until it reaches a bin.

1. Write the classes and their attributes representing:
   - Package
   - Machine
   - ConveyorEdge
   - SortingGraph

2. Given a package, determine which bin it reaches.

Rules:
- Package has type and weight.
- Edges are checked in the order they were added.
- A default edge matches any package, so it should usually be added last.
- If multiple edges match, use the first matching edge.
- If no edge matches, print REJECTED.
- If the package visits the same machine twice, print LOOP.
- A bin is a machine marked as isBin = true.

EX:

(Start) --default--> (Scanner)

(Scanner) --type=A--> (BinA)
(Scanner) --type=B--> (HeavyCheck)

(HeavyCheck) --weight>=10--> (BinB)
(HeavyCheck) --default-----> (RejectedBin)

Package:
type = B
weight = 12

Expected output:
BinB
*/

# Virus Spread Graph
Solution: (none yet)

/*
Given a graph representing people and infection delay.

Each person is a node.
Each undirected edge has a delay in days.
If person A is infected, the infection can spread to connected people after the edge delay.

1. Write the classes and their attributes representing:
   - Person
   - Contact
   - InfectionGraph

2. Given one initially infected person and a number of days D,
   print all people infected within D days.

Rules:
- Infection starts at day 0.
- A person should be counted if their earliest infection day <= D.
- All delays are positive.

EX:

(Alice) --2-- (Bob) --3-- (Dana)
   |
   5
   |
(Chris)

Start infected:
Alice

D = 4

Expected output:
Alice Bob
*/

# Build Dependency Graph
Solution: (none yet)

/*
Given a graph representing software build dependencies.

Each module is a node.
Each module has a build time.
A directed edge A -> B means B depends on A.

1. Write the classes and their attributes representing:
   - Module
   - DependencyGraph

2. Given one changed module, print all modules that must be rebuilt.

3. Return the minimum total build time if independent modules can build in parallel.

Rules:
- The graph must be a DAG.
- If there is a cycle, print INVALID.
- The changed module itself must also be rebuilt.
- A module can build only after all affected dependencies before it are rebuilt.

EX:

(Parser: 3) ---> (Compiler: 7) ---> (App: 2)
     |
     v
(Tests: 4) -----------------------> (App: 2)

Changed module:
Parser

Expected affected modules:
Parser Compiler Tests App

Expected parallel build time:
12
*/

# Treasure Map Graph
Solution: (none yet)

/*
Given a graph representing islands connected by bridges.

Each island is a node.
Each island contains some coins.
Each undirected bridge has an energy cost.

1. Write the classes and their attributes representing:
   - Island
   - Bridge
   - TreasureGraph

2. Given a starting island and maximum energy,
   return the maximum coins that can be collected.

Rules:
- You start at the starting island.
- You collect coins from an island only once.
- You may not visit the same island twice in one path.
- You do not need to return to the starting island.
- Total bridge cost must be <= energy.

EX:

(Start: 0) --3-- (A: 5) --4-- (C: 20)
     |
     2
     |
   (B: 8) --5-- (C: 20)

Energy = 7

Expected output:
28
*/