# Competitive Programming Solutions

Solutions organized **by topic**. Each file is prefixed with its source platform:

| Prefix | Platform |
|---|---|
| `cf-` | [Codeforces](https://codeforces.com/profile/Andrew744) |
| `lc-` | [LeetCode](https://leetcode.com/u/Andrw744/) |
| `cses-` | CSES |
| `cw-` | Codewars |
| `ex-` | Graph course exercises |
| `practice-` | Practice snippets |

## How each file is laid out

1. **Header**: problem name, link, topic, tags, and the complexity of my solution.
2. **My solution**, unchanged.
3. **`namespace optimized` / `class SolutionOptimized`** (only when there is a better or corrected approach). To submit it, swap it in for `solve()` / `Solution`.
4. **Notes block**: 💭 first idea · 🧩 invariant · ✅ key insight · 🔁 recognition cue · ⏱ speed fix · 🛠 review.

Legend: ✅ correct · ⚠️ my original was wrong (a fix is in the file) · 🧩 my original was unfinished (a solution was added) · ⚡ optimized version added

## Topics

[arrays](#arrays) (21) · [binary-search](#binary-search) (4) · [bit-manipulation](#bit-manipulation) (3) · [brute-force](#brute-force) (10) · [constructive](#constructive) (6) · [design](#design) (2) · [dynamic-programming](#dynamic-programming) (5) · [game-theory](#game-theory) (2) · [geometry](#geometry) (4) · [graphs](#graphs) (15) · [greedy](#greedy) (40) · [hashing](#hashing) (25) · [heap](#heap) (1) · [implementation](#implementation) (52) · [linked-list](#linked-list) (3) · [math](#math) (76) · [matrix](#matrix) (7) · [prefix-sum](#prefix-sum) (4) · [sliding-window](#sliding-window) (2) · [sorting](#sorting) (16) · [stack](#stack) (6) · [strings](#strings) (93) · [templates](#templates) (1) · [trees](#trees) (9) · [two-pointers](#two-pointers) (2)

**409 files**: Codeforces 210, Codewars 108, LeetCode 73, Graph exercises 10, Practice 6, CSES 2

## arrays

| File | Problem | Status |
|---|---|---|
| [`cf-1829B.cpp`](arrays/cf-1829B.cpp) | [CF 1829B — Blank Space](https://codeforces.com/problemset/problem/1829/B) | ✅ |
| [`cf-1878A.cpp`](arrays/cf-1878A.cpp) | [CF 1878A — How Much Does Daytona Cost?](https://codeforces.com/problemset/problem/1878/A) | ✅ |
| [`cf-2141A.cpp`](arrays/cf-2141A.cpp) | [CF 2141A — Furniture Store](https://codeforces.com/problemset/problem/2141/A) | ✅ |
| [`lc-1184.cpp`](arrays/lc-1184.cpp) | [LC 1184 — Distance Between Bus Stops](https://leetcode.com/problems/distance-between-bus-stops/) | ✅ |
| [`lc-1550.cpp`](arrays/lc-1550.cpp) | [LC 1550 — Three Consecutive Odds](https://leetcode.com/problems/three-consecutive-odds/) | ✅ |
| [`lc-1566.cpp`](arrays/lc-1566.cpp) | [LC 1566 — Detect Pattern of Length M Repeated K or More Times](https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/) | ✅ |
| [`lc-3379.cpp`](arrays/lc-3379.cpp) | [LC 3379 — Transformed Array](https://leetcode.com/problems/transformed-array/) | ✅ |
| [`lc-3637.cpp`](arrays/lc-3637.cpp) | [LC 3637 — Trionic Array I](https://leetcode.com/problems/trionic-array-i/) | ✅ |
| [`cw-a-needle-in-the-haystack.cpp`](arrays/cw-a-needle-in-the-haystack.cpp) | Codewars — A Needle in the Haystack | ✅ |
| [`cw-computer-problem-series-1-fill-the-hard-disk-drive.cpp`](arrays/cw-computer-problem-series-1-fill-the-hard-disk-drive.cpp) | Codewars — Computer problem series #1: Fill the Hard Disk Drive | ✅ |
| [`cw-consecutive-items.cpp`](arrays/cw-consecutive-items.cpp) | Codewars — Consecutive items | ✅ ⚡ |
| [`cw-count-of-positives-sum-of-negatives.cpp`](arrays/cw-count-of-positives-sum-of-negatives.cpp) | Codewars — Count of positives / sum of negatives | ✅ |
| [`cw-find-numbers-which-are-divisible-by-given-number.cpp`](arrays/cw-find-numbers-which-are-divisible-by-given-number.cpp) | Codewars — Find numbers which are divisible by given number | ✅ |
| [`cw-find-the-parity-outlier.cpp`](arrays/cw-find-the-parity-outlier.cpp) | Codewars — Find The Parity Outlier | ✅ |
| [`cw-invert-values.cpp`](arrays/cw-invert-values.cpp) | Codewars — Invert values | ✅ |
| [`cw-javascript-array-filter.cpp`](arrays/cw-javascript-array-filter.cpp) | Codewars — JavaScript Array Filter (C++: get_even_numbers) | ✅ |
| [`cw-simple-consecutive-pairs.cpp`](arrays/cw-simple-consecutive-pairs.cpp) | [Codewars — Simple consecutive pairs](https://www.codewars.com/kata/5a3e1319b6486ac96f000049) | ✅ ⚡ |
| [`cw-small-enough.cpp`](arrays/cw-small-enough.cpp) | Codewars — Small enough? - Beginner | ✅ |
| [`cw-sum-of-minimums.cpp`](arrays/cw-sum-of-minimums.cpp) | Codewars — Sum of Minimums! | ✅ |
| [`cw-the-highest-profit-wins.cpp`](arrays/cw-the-highest-profit-wins.cpp) | [Codewars — The highest profit wins!](https://www.codewars.com/kata/559590633066759614000063) | ✅ |
| [`cw-the-office-iv-find-a-meeting-room.cpp`](arrays/cw-the-office-iv-find-a-meeting-room.cpp) | Codewars — The Office IV - Find a Meeting Room | ✅ |

## binary-search

| File | Problem | Status |
|---|---|---|
| [`lc-278.cpp`](binary-search/lc-278.cpp) | [LC 278 — First Bad Version](https://leetcode.com/problems/first-bad-version/) | ✅ |
| [`lc-2389.cpp`](binary-search/lc-2389.cpp) | [LC 2389 — Longest Subsequence With Limited Sum](https://leetcode.com/problems/longest-subsequence-with-limited-sum/) | ✅ |
| [`lc-3453.cpp`](binary-search/lc-3453.cpp) | [LC 3453 — Separate Squares I](https://leetcode.com/problems/separate-squares-i/) | ✅ ⚡ |
| [`practice-binary-search.cpp`](binary-search/practice-binary-search.cpp) | Practice — Binary Search | ⚠️ |

## bit-manipulation

| File | Problem | Status |
|---|---|---|
| [`cw-evil-or-odious.cpp`](bit-manipulation/cw-evil-or-odious.cpp) | Codewars — Evil or Odious | ✅ |
| [`cw-find-the-odd-int.cpp`](bit-manipulation/cw-find-the-odd-int.cpp) | Codewars — Find the odd int | ✅ ⚡ |
| [`cw-reverse-the-bits-in-an-integer.cpp`](bit-manipulation/cw-reverse-the-bits-in-an-integer.cpp) | Codewars — Reverse the bits in an integer | ✅ |

## brute-force

| File | Problem | Status |
|---|---|---|
| [`cf-214A.cpp`](brute-force/cf-214A.cpp) | [CF 214A — System of Equations](https://codeforces.com/problemset/problem/214/A) | ✅ ⚡ |
| [`cf-268A.cpp`](brute-force/cf-268A.cpp) | [CF 268A — Games](https://codeforces.com/problemset/problem/268/A) | ✅ ⚡ |
| [`cf-271A.cpp`](brute-force/cf-271A.cpp) | [CF 271A — Beautiful Year](https://codeforces.com/problemset/problem/271/A) | ✅ |
| [`cf-1560A.cpp`](brute-force/cf-1560A.cpp) | [CF 1560A — Dislike of Threes](https://codeforces.com/problemset/problem/1560/A) | ✅ |
| [`cf-1808A.cpp`](brute-force/cf-1808A.cpp) | [CF 1808A — Lucky Numbers](https://codeforces.com/problemset/problem/1808/A) | ✅ |
| [`cf-1829D.cpp`](brute-force/cf-1829D.cpp) | [CF 1829D — Gold Rush](https://codeforces.com/problemset/problem/1829/D) | ✅ |
| [`cf-1904A.cpp`](brute-force/cf-1904A.cpp) | [CF 1904A — Forked!](https://codeforces.com/problemset/problem/1904/A) | ✅ |
| [`cf-2172E.cpp`](brute-force/cf-2172E.cpp) | [CF 2172E — Number Maze](https://codeforces.com/problemset/problem/2172/E) | ✅ |
| [`cf-2182B.cpp`](brute-force/cf-2182B.cpp) | [CF 2182B — New Year Cake](https://codeforces.com/problemset/problem/2182/B) | ✅ |
| [`cf-2236C.cpp`](brute-force/cf-2236C.cpp) | [CF 2236C — Omsk Programmers](https://codeforces.com/problemset/problem/2236/C) | ✅ |

## constructive

| File | Problem | Status |
|---|---|---|
| [`cf-445A.cpp`](constructive/cf-445A.cpp) | [CF 445A — DZY Loves Chessboard](https://codeforces.com/problemset/problem/445/A) | 🧩 |
| [`cf-2048B.cpp`](constructive/cf-2048B.cpp) | [CF 2048B — Kevin and Permutation](https://codeforces.com/problemset/problem/2048/B) | ✅ |
| [`cf-2069A.cpp`](constructive/cf-2069A.cpp) | [CF 2069A — Was there an Array?](https://codeforces.com/problemset/problem/2069/A) | ✅ |
| [`cf-2147B.cpp`](constructive/cf-2147B.cpp) | [CF 2147B — Multiple Construction](https://codeforces.com/problemset/problem/2147/B) | ✅ |
| [`cf-2227C.cpp`](constructive/cf-2227C.cpp) | [CF 2227C — Snowfall](https://codeforces.com/problemset/problem/2227/C) | ✅ |
| [`cf-2241B.cpp`](constructive/cf-2241B.cpp) | [CF 2241B — Good times Good times](https://codeforces.com/problemset/problem/2241/B) | ✅ |

## design

| File | Problem | Status |
|---|---|---|
| [`lc-1195.cpp`](design/lc-1195.cpp) | [LC 1195 — Fizz Buzz Multithreaded](https://leetcode.com/problems/fizz-buzz-multithreaded/) | ✅ |
| [`cw-playing-with-cubes-i.cpp`](design/cw-playing-with-cubes-i.cpp) | Codewars — Playing with cubes I | ✅ |

## dynamic-programming

| File | Problem | Status |
|---|---|---|
| [`lc-712.cpp`](dynamic-programming/lc-712.cpp) | [LC 712 — Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) | ✅ |
| [`lc-1458.cpp`](dynamic-programming/lc-1458.cpp) | [LC 1458 — Max Dot Product of Two Subsequences](https://leetcode.com/problems/max-dot-product-of-two-subsequences/) | ✅ |
| [`lc-2267.cpp`](dynamic-programming/lc-2267.cpp) | [LC 2267 — Check if There Is a Valid Parentheses String Path](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/) | ✅ |
| [`lc-3640.cpp`](dynamic-programming/lc-3640.cpp) | [LC 3640 — Trionic Array II](https://leetcode.com/problems/trionic-array-ii/) | ✅ |
| [`practice-fibonacci.cpp`](dynamic-programming/practice-fibonacci.cpp) | Practice — Fibonacci (nth Number) | ✅ |

## game-theory

| File | Problem | Status |
|---|---|---|
| [`cf-1972B.cpp`](game-theory/cf-1972B.cpp) | [CF 1972B — Coin Games](https://codeforces.com/problemset/problem/1972/B) | ✅ |
| [`cf-2042B.cpp`](game-theory/cf-2042B.cpp) | [CF 2042B — Game with Colored Marbles](https://codeforces.com/problemset/problem/2042/B) | ✅ |

## geometry

| File | Problem | Status |
|---|---|---|
| [`cf-1033A.cpp`](geometry/cf-1033A.cpp) | [CF 1033A — King Escape](https://codeforces.com/problemset/problem/1033/A) | ✅ ⚡ |
| [`lc-1266.cpp`](geometry/lc-1266.cpp) | [LC 1266 — Minimum Time Visiting All Points](https://leetcode.com/problems/minimum-time-visiting-all-points/) | ✅ |
| [`lc-3047.cpp`](geometry/lc-3047.cpp) | [LC 3047 — Find the Largest Area of Square Inside Two Rectangles](https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/) | ✅ |
| [`cw-localize-the-barycenter-of-a-triangle.cpp`](geometry/cw-localize-the-barycenter-of-a-triangle.cpp) | Codewars — Localize The Barycenter of a Triangle | ✅ |

## graphs

| File | Problem | Status |
|---|---|---|
| [`cf-1598A.cpp`](graphs/cf-1598A.cpp) | [CF 1598A — Computer Game](https://codeforces.com/problemset/problem/1598/A) | ✅ ⚡ |
| [`cf-1829E.cpp`](graphs/cf-1829E.cpp) | [CF 1829E — The Lakes](https://codeforces.com/problemset/problem/1829/E) | ✅ ⚡ |
| [`lc-3650.cpp`](graphs/lc-3650.cpp) | [LC 3650 — Minimum Cost Path with Edge Reversals](https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/) | ✅ |
| [`cses-1192.cpp`](graphs/cses-1192.cpp) | [CSES 1192 — Counting Rooms](https://cses.fi/problemset/task/1192) | ✅ ⚡ |
| [`cses-1193.cpp`](graphs/cses-1193.cpp) | [CSES 1193 — Labyrinth](https://cses.fi/problemset/task/1193) | ✅ |
| [`ex-activity-graph.cpp`](graphs/ex-activity-graph.cpp) | Graph exercise — Activity Graph (remove API + simulate start times) | ✅ |
| [`ex-bfs-princeton.cpp`](graphs/ex-bfs-princeton.cpp) | [Algs4 BreadthFirstPaths (Princeton)](https://algs4.cs.princeton.edu/41graph/BreadthFirstPaths.java.html) | 🧩 |
| [`ex-bfs.cpp`](graphs/ex-bfs.cpp) | [Rosalind BFS — Breadth-First Search](https://rosalind.info/problems/bfs/) | ⚠️ |
| [`ex-connected-components.cpp`](graphs/ex-connected-components.cpp) | [Rosalind CC — Connected Components](https://rosalind.info/problems/cc/) | ✅ |
| [`ex-dynamic-word-match.cpp`](graphs/ex-dynamic-word-match.cpp) | Graph exercise — Dynamic Word Matching Graph (DFA with add/remove APIs) | ⚠️ |
| [`ex-key-room-escape.cpp`](graphs/ex-key-room-escape.cpp) | Graph exercise — Key-Room Escape Graph | 🧩 |
| [`ex-questions.md`](graphs/ex-questions.md) | Graph course exercise sheet (7 questions) | ✅ |
| [`ex-random-activity.cpp`](graphs/ex-random-activity.cpp) | Graph exercise — Random Activity Diagram with exact execution time | ✅ ⚡ |
| [`ex-semi-connected.cpp`](graphs/ex-semi-connected.cpp) | [Rosalind SC — Semi-Connected Graph](https://rosalind.info/problems/sc/) | ✅ ⚡ |
| [`ex-word-match.cpp`](graphs/ex-word-match.cpp) | Graph exercise — Word Matching Graph | ⚠️ |

## greedy

| File | Problem | Status |
|---|---|---|
| [`cf-144A.cpp`](greedy/cf-144A.cpp) | [CF 144A — Arrival of the General](https://codeforces.com/problemset/problem/144/A) | ✅ |
| [`cf-490A.cpp`](greedy/cf-490A.cpp) | [CF 490A — Team Olympiad](https://codeforces.com/problemset/problem/490/A) | ✅ |
| [`cf-520B.cpp`](greedy/cf-520B.cpp) | [CF 520B — Two Buttons](https://codeforces.com/problemset/problem/520/B) | ✅ |
| [`cf-727A.cpp`](greedy/cf-727A.cpp) | [CF 727A — Transformation: from A to B](https://codeforces.com/problemset/problem/727/A) | ✅ |
| [`cf-910A.cpp`](greedy/cf-910A.cpp) | [CF 910A — The Way to Home](https://codeforces.com/problemset/problem/910/A) | ⚠️ |
| [`cf-910C.cpp`](greedy/cf-910C.cpp) | [CF 910C — Minimum Sum](https://codeforces.com/problemset/problem/910/C) | ✅ |
| [`cf-996A.cpp`](greedy/cf-996A.cpp) | [CF 996A — Hit the Lottery](https://codeforces.com/problemset/problem/996/A) | ✅ |
| [`cf-1324C.cpp`](greedy/cf-1324C.cpp) | [CF 1324C — Frog Jumps](https://codeforces.com/problemset/problem/1324/C) | ✅ |
| [`cf-1549B.cpp`](greedy/cf-1549B.cpp) | [CF 1549B — Gregor and the Pawn Game](https://codeforces.com/problemset/problem/1549/B) | ✅ |
| [`cf-1807B.cpp`](greedy/cf-1807B.cpp) | [CF 1807B — Grab the Candies](https://codeforces.com/problemset/problem/1807/B) | ✅ |
| [`cf-1856A.cpp`](greedy/cf-1856A.cpp) | [CF 1856A — Tales of a Sort](https://codeforces.com/problemset/problem/1856/A) | ✅ |
| [`cf-1873D.cpp`](greedy/cf-1873D.cpp) | [CF 1873D — 1D Eraser](https://codeforces.com/problemset/problem/1873/D) | ✅ |
| [`cf-1900A.cpp`](greedy/cf-1900A.cpp) | [CF 1900A — Cover in Water](https://codeforces.com/problemset/problem/1900/A) | ✅ |
| [`cf-1901A.cpp`](greedy/cf-1901A.cpp) | [CF 1901A — Line Trip](https://codeforces.com/problemset/problem/1901/A) | ✅ |
| [`cf-1923A.cpp`](greedy/cf-1923A.cpp) | [CF 1923A — Moving Chips](https://codeforces.com/problemset/problem/1923/A) | ✅ |
| [`cf-1993A.cpp`](greedy/cf-1993A.cpp) | [CF 1993A — Question Marks](https://codeforces.com/problemset/problem/1993/A) | ✅ |
| [`cf-2001A.cpp`](greedy/cf-2001A.cpp) | [CF 2001A — Make All Equal](https://codeforces.com/problemset/problem/2001/A) | ✅ |
| [`cf-2036B.cpp`](greedy/cf-2036B.cpp) | [CF 2036B — Startup](https://codeforces.com/problemset/problem/2036/B) | ✅ |
| [`cf-2050A.cpp`](greedy/cf-2050A.cpp) | [CF 2050A — Line Breaks](https://codeforces.com/problemset/problem/2050/A) | ✅ |
| [`cf-2064A.cpp`](greedy/cf-2064A.cpp) | [CF 2064A — Brogramming Contest](https://codeforces.com/problemset/problem/2064/A) | ✅ |
| [`cf-2065B.cpp`](greedy/cf-2065B.cpp) | [CF 2065B — Skibidus and Ohio](https://codeforces.com/problemset/problem/2065/B) | ✅ |
| [`cf-2134C.cpp`](greedy/cf-2134C.cpp) | [CF 2134C — Even Larger](https://codeforces.com/problemset/problem/2134/C) | ✅ |
| [`cf-2149C.cpp`](greedy/cf-2149C.cpp) | [CF 2149C — MEX rose](https://codeforces.com/problemset/problem/2149/C) | ⚠️ |
| [`cf-2154A.cpp`](greedy/cf-2154A.cpp) | [CF 2154A — Notelock](https://codeforces.com/problemset/problem/2154/A) | ✅ |
| [`cf-2161A.cpp`](greedy/cf-2161A.cpp) | [CF 2161A — Round Trip](https://codeforces.com/problemset/problem/2161/A) | 🧩 |
| [`cf-2169A.cpp`](greedy/cf-2169A.cpp) | [CF 2169A — Alice and Bob](https://codeforces.com/problemset/problem/2169/A) | ⚠️ |
| [`cf-2173A.cpp`](greedy/cf-2173A.cpp) | [CF 2173A — Sleeping Through Classes](https://codeforces.com/problemset/problem/2173/A) | ✅ |
| [`cf-2176A.cpp`](greedy/cf-2176A.cpp) | [CF 2176A — Operations with Inversions](https://codeforces.com/problemset/problem/2176/A) | ✅ |
| [`cf-2180B.cpp`](greedy/cf-2180B.cpp) | [CF 2180B — Ashmal](https://codeforces.com/problemset/problem/2180/B) | ⚠️ |
| [`cf-2185B.cpp`](greedy/cf-2185B.cpp) | [CF 2185B — Prefix Max](https://codeforces.com/problemset/problem/2185/B) | ✅ |
| [`cf-2189A.cpp`](greedy/cf-2189A.cpp) | [CF 2189A — Table with Numbers](https://codeforces.com/problemset/problem/2189/A) | 🧩 |
| [`cf-2193B.cpp`](greedy/cf-2193B.cpp) | [CF 2193B — Reverse a Permutation](https://codeforces.com/problemset/problem/2193/B) | ⚠️ |
| [`cf-2229C1.cpp`](greedy/cf-2229C1.cpp) | [CF 2229C1 — We Be Flipping (Easy Version)](https://codeforces.com/problemset/problem/2229/C1) | ✅ |
| [`cf-2241D.cpp`](greedy/cf-2241D.cpp) | [CF 2241D — An Alternative Way](https://codeforces.com/problemset/problem/2241/D) | 🧩 |
| [`cf-2244B.cpp`](greedy/cf-2244B.cpp) | [CF 2244B — Nikita and Books](https://codeforces.com/problemset/problem/2244/B) | ⚠️ |
| [`lc-561.cpp`](greedy/lc-561.cpp) | [LC 561 — Array Partition](https://leetcode.com/problems/array-partition/) | ✅ |
| [`lc-605.cpp`](greedy/lc-605.cpp) | [LC 605 — Can Place Flowers](https://leetcode.com/problems/can-place-flowers/) | ✅ |
| [`lc-1877.cpp`](greedy/lc-1877.cpp) | [LC 1877 — Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/) | ✅ |
| [`lc-1975.cpp`](greedy/lc-1975.cpp) | [LC 1975 — Maximum Matrix Sum](https://leetcode.com/problems/maximum-matrix-sum/) | ✅ |
| [`cw-minimize-sum-of-array.cpp`](greedy/cw-minimize-sum-of-array.cpp) | Codewars — Minimize Sum Of Array (Array Series #1) | ✅ |

## hashing

| File | Problem | Status |
|---|---|---|
| [`cf-141A.cpp`](hashing/cf-141A.cpp) | [CF 141A — Amusing Joke](https://codeforces.com/problemset/problem/141/A) | ✅ |
| [`cf-228A.cpp`](hashing/cf-228A.cpp) | [CF 228A — Is your horseshoe on the other foot?](https://codeforces.com/problemset/problem/228/A) | ✅ |
| [`cf-236A.cpp`](hashing/cf-236A.cpp) | [CF 236A — Boy or Girl](https://codeforces.com/problemset/problem/236/A) | ✅ |
| [`cf-469A.cpp`](hashing/cf-469A.cpp) | [CF 469A — I Wanna Be the Guy](https://codeforces.com/problemset/problem/469/A) | ✅ |
| [`cf-1325B.cpp`](hashing/cf-1325B.cpp) | [CF 1325B — CopyCopyCopyCopyCopy](https://codeforces.com/problemset/problem/1325/B) | ✅ |
| [`cf-1607A.cpp`](hashing/cf-1607A.cpp) | [CF 1607A — Linear Keyboard](https://codeforces.com/problemset/problem/1607/A) | ✅ |
| [`cf-1669B.cpp`](hashing/cf-1669B.cpp) | [CF 1669B — Triple](https://codeforces.com/problemset/problem/1669/B) | ✅ |
| [`cf-1703B.cpp`](hashing/cf-1703B.cpp) | [CF 1703B — ICPC Balloons](https://codeforces.com/problemset/problem/1703/B) | ✅ |
| [`cf-1836A.cpp`](hashing/cf-1836A.cpp) | [CF 1836A — Destroyer](https://codeforces.com/problemset/problem/1836/A) | ✅ |
| [`cf-1914A.cpp`](hashing/cf-1914A.cpp) | [CF 1914A — Problemsolving Log](https://codeforces.com/problemset/problem/1914/A) | ✅ |
| [`cf-2000C.cpp`](hashing/cf-2000C.cpp) | [CF 2000C — Numeric String Template](https://codeforces.com/problemset/problem/2000/C) | ✅ ⚡ |
| [`cf-2037A.cpp`](hashing/cf-2037A.cpp) | [CF 2037A — Twice](https://codeforces.com/problemset/problem/2037/A) | ✅ |
| [`cf-2146A.cpp`](hashing/cf-2146A.cpp) | [CF 2146A — Equal Occurrences](https://codeforces.com/problemset/problem/2146/A) | ✅ |
| [`cf-2157A.cpp`](hashing/cf-2157A.cpp) | [CF 2157A — Dungeon Equilibrium](https://codeforces.com/problemset/problem/2157/A) | ✅ |
| [`cf-2167B.cpp`](hashing/cf-2167B.cpp) | [CF 2167B — Your Name](https://codeforces.com/problemset/problem/2167/B) | ✅ |
| [`lc-961.cpp`](hashing/lc-961.cpp) | [LC 961 — N-Repeated Element in Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/) | ✅ ⚡ |
| [`lc-1160.cpp`](hashing/lc-1160.cpp) | [LC 1160 — Find Words That Can Be Formed by Characters](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/) | ✅ |
| [`lc-1189.cpp`](hashing/lc-1189.cpp) | [LC 1189 — Maximum Number of Balloons](https://leetcode.com/problems/maximum-number-of-balloons/) | ✅ |
| [`lc-2006.cpp`](hashing/lc-2006.cpp) | [LC 2006 — Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/) | ✅ ⚡ |
| [`lc-2395.cpp`](hashing/lc-2395.cpp) | [LC 2395 — Find Subarrays With Equal Sum](https://leetcode.com/problems/find-subarrays-with-equal-sum/) | ✅ |
| [`lc-2423.cpp`](hashing/lc-2423.cpp) | [LC 2423 — Remove Letter To Equalize Frequency](https://leetcode.com/problems/remove-letter-to-equalize-frequency/) | ✅ |
| [`lc-3663.cpp`](hashing/lc-3663.cpp) | [LC 3663 — Find The Least Frequent Digit](https://leetcode.com/problems/find-the-least-frequent-digit/) | ✅ |
| [`lc-3719.cpp`](hashing/lc-3719.cpp) | [LC 3719 — Longest Balanced Subarray I](https://leetcode.com/problems/longest-balanced-subarray-i/) | ✅ |
| [`cw-count-characters-in-your-string.cpp`](hashing/cw-count-characters-in-your-string.cpp) | Codewars — Count characters in your string | ✅ |
| [`cw-isograms.cpp`](hashing/cw-isograms.cpp) | Codewars — Isograms | ✅ |

## heap

| File | Problem | Status |
|---|---|---|
| [`lc-3510.cpp`](heap/lc-3510.cpp) | [LC 3510 — Minimum Pair Removal to Sort Array II](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/) | ✅ |

## implementation

| File | Problem | Status |
|---|---|---|
| [`cf-116A.cpp`](implementation/cf-116A.cpp) | [CF 116A — Tram](https://codeforces.com/problemset/problem/116/A) | ✅ |
| [`cf-155A.cpp`](implementation/cf-155A.cpp) | [CF 155A — I_love_%username%](https://codeforces.com/problemset/problem/155/A) | ✅ |
| [`cf-158A.cpp`](implementation/cf-158A.cpp) | [CF 158A — Next Round](https://codeforces.com/problemset/problem/158/A) | ✅ |
| [`cf-231A.cpp`](implementation/cf-231A.cpp) | [CF 231A — Team](https://codeforces.com/problemset/problem/231/A) | ✅ |
| [`cf-282A.cpp`](implementation/cf-282A.cpp) | [CF 282A — Bit++](https://codeforces.com/problemset/problem/282/A) | ✅ |
| [`cf-344A.cpp`](implementation/cf-344A.cpp) | [CF 344A — Magnets](https://codeforces.com/problemset/problem/344/A) | ✅ |
| [`cf-427A.cpp`](implementation/cf-427A.cpp) | [CF 427A — Police Recruits](https://codeforces.com/problemset/problem/427/A) | ✅ |
| [`cf-431A.cpp`](implementation/cf-431A.cpp) | [CF 431A — Black Square](https://codeforces.com/problemset/problem/431/A) | ✅ |
| [`cf-467A.cpp`](implementation/cf-467A.cpp) | [CF 467A — George and Accommodation](https://codeforces.com/problemset/problem/467/A) | ✅ |
| [`cf-500A.cpp`](implementation/cf-500A.cpp) | [CF 500A — New Year Transportation](https://codeforces.com/problemset/problem/500/A) | ✅ |
| [`cf-510A.cpp`](implementation/cf-510A.cpp) | [CF 510A — Fox And Snake](https://codeforces.com/problemset/problem/510/A) | ✅ |
| [`cf-677A.cpp`](implementation/cf-677A.cpp) | [CF 677A — Vanya and Fence](https://codeforces.com/problemset/problem/677/A) | ✅ |
| [`cf-703A.cpp`](implementation/cf-703A.cpp) | [CF 703A — Mishka and Game](https://codeforces.com/problemset/problem/703/A) | ✅ |
| [`cf-705A.cpp`](implementation/cf-705A.cpp) | [CF 705A — Hulk](https://codeforces.com/problemset/problem/705/A) | ✅ |
| [`cf-750A.cpp`](implementation/cf-750A.cpp) | [CF 750A — New Year and Hurry](https://codeforces.com/problemset/problem/750/A) | ✅ |
| [`cf-785A.cpp`](implementation/cf-785A.cpp) | [CF 785A — Anton and Polyhedrons](https://codeforces.com/problemset/problem/785/A) | ✅ |
| [`cf-791A.cpp`](implementation/cf-791A.cpp) | [CF 791A — Bear and Big Brother](https://codeforces.com/problemset/problem/791/A) | ✅ |
| [`cf-948A.cpp`](implementation/cf-948A.cpp) | [CF 948A — Protect Sheep](https://codeforces.com/problemset/problem/948/A) | ✅ |
| [`cf-977A.cpp`](implementation/cf-977A.cpp) | [CF 977A — Wrong Subtraction](https://codeforces.com/problemset/problem/977/A) | ✅ |
| [`cf-1030A.cpp`](implementation/cf-1030A.cpp) | [CF 1030A — In Search of an Easy Problem](https://codeforces.com/problemset/problem/1030/A) | ✅ |
| [`cf-1512A.cpp`](implementation/cf-1512A.cpp) | [CF 1512A — Spy Detected!](https://codeforces.com/problemset/problem/1512/A) | ✅ |
| [`cf-1535A.cpp`](implementation/cf-1535A.cpp) | [CF 1535A — Fair Playoff](https://codeforces.com/problemset/problem/1535/A) | ✅ |
| [`cf-1669A.cpp`](implementation/cf-1669A.cpp) | [CF 1669A — Division?](https://codeforces.com/problemset/problem/1669/A) | ✅ |
| [`cf-1692A.cpp`](implementation/cf-1692A.cpp) | [CF 1692A — Marathon](https://codeforces.com/problemset/problem/1692/A) | ✅ |
| [`cf-1809A.cpp`](implementation/cf-1809A.cpp) | [CF 1809A — Garland](https://codeforces.com/problemset/problem/1809/A) | ✅ |
| [`cf-1907A.cpp`](implementation/cf-1907A.cpp) | [CF 1907A — Rook](https://codeforces.com/problemset/problem/1907/A) | ✅ |
| [`cf-1950A.cpp`](implementation/cf-1950A.cpp) | [CF 1950A — Stair, Peak, or Neither?](https://codeforces.com/problemset/problem/1950/A) | ✅ |
| [`cf-1971A.cpp`](implementation/cf-1971A.cpp) | [CF 1971A — My First Sorting Problem](https://codeforces.com/problemset/problem/1971/A) | ✅ |
| [`cf-1971C.cpp`](implementation/cf-1971C.cpp) | [CF 1971C — Clock and Strings](https://codeforces.com/problemset/problem/1971/C) | ✅ |
| [`cf-1999C.cpp`](implementation/cf-1999C.cpp) | [CF 1999C — Showering](https://codeforces.com/problemset/problem/1999/C) | ✅ |
| [`cf-2009B.cpp`](implementation/cf-2009B.cpp) | [CF 2009B — osu!mania](https://codeforces.com/problemset/problem/2009/B) | ✅ |
| [`cf-2014A.cpp`](implementation/cf-2014A.cpp) | [CF 2014A — Robin Helps](https://codeforces.com/problemset/problem/2014/A) | ✅ |
| [`cf-2036A.cpp`](implementation/cf-2036A.cpp) | [CF 2036A — Quintomania](https://codeforces.com/problemset/problem/2036/A) | ✅ |
| [`cf-2038J.cpp`](implementation/cf-2038J.cpp) | [CF 2038J — Waiting for...](https://codeforces.com/problemset/problem/2038/J) | ✅ |
| [`cf-2038N.cpp`](implementation/cf-2038N.cpp) | [CF 2038N — Fixing the Expression](https://codeforces.com/problemset/problem/2038/N) | ✅ ⚡ |
| [`cf-2090B.cpp`](implementation/cf-2090B.cpp) | [CF 2090B — Pushing Balls](https://codeforces.com/problemset/problem/2090/B) | ✅ ⚡ |
| [`cf-2109A.cpp`](implementation/cf-2109A.cpp) | [CF 2109A — It's Time To Duel](https://codeforces.com/problemset/problem/2109/A) | ✅ |
| [`cf-2117A.cpp`](implementation/cf-2117A.cpp) | [CF 2117A — False Alarm](https://codeforces.com/problemset/problem/2117/A) | ✅ |
| [`cf-2145B.cpp`](implementation/cf-2145B.cpp) | [CF 2145B — Deck of Cards](https://codeforces.com/problemset/problem/2145/B) | ✅ |
| [`cf-2156B.cpp`](implementation/cf-2156B.cpp) | [CF 2156B — Strange Machine](https://codeforces.com/problemset/problem/2156/B) | ⚠️ |
| [`cf-2167A.cpp`](implementation/cf-2167A.cpp) | [CF 2167A — Square?](https://codeforces.com/problemset/problem/2167/A) | ✅ |
| [`cf-2169B.cpp`](implementation/cf-2169B.cpp) | [CF 2169B — Drifting Away](https://codeforces.com/problemset/problem/2169/B) | ✅ |
| [`cf-2172A.cpp`](implementation/cf-2172A.cpp) | [CF 2172A — ASCII Art Contest](https://codeforces.com/problemset/problem/2172/A) | ✅ |
| [`cf-2204A.cpp`](implementation/cf-2204A.cpp) | [CF 2204A — Passing the Ball](https://codeforces.com/problemset/problem/2204/A) | ✅ |
| [`lc-657.cpp`](implementation/lc-657.cpp) | [LC 657 — Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/) | ✅ |
| [`lc-2011.cpp`](implementation/lc-2011.cpp) | [LC 2011 — Final Value of Variable After Performing Operations](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/) | ✅ |
| [`lc-3507.cpp`](implementation/lc-3507.cpp) | [LC 3507 — Minimum Pair Removal to Sort Array I](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/) | ✅ |
| [`cw-finish-guess-the-number-game.cpp`](implementation/cw-finish-guess-the-number-game.cpp) | Codewars — Finish Guess the Number Game | ✅ |
| [`cw-keep-up-the-hoop.cpp`](implementation/cw-keep-up-the-hoop.cpp) | Codewars — Keep up the hoop | ✅ |
| [`cw-l1-set-alarm.cpp`](implementation/cw-l1-set-alarm.cpp) | Codewars — L1: Set Alarm | ✅ ⚡ |
| [`cw-whats-the-real-floor.cpp`](implementation/cw-whats-the-real-floor.cpp) | Codewars — What's the real floor? | ✅ |
| [`cw-who-likes-it.cpp`](implementation/cw-who-likes-it.cpp) | [Codewars — Who likes it?](https://www.codewars.com/kata/5266876b8f4bf2da9b000362) | ✅ |

## linked-list

| File | Problem | Status |
|---|---|---|
| [`lc-19.cpp`](linked-list/lc-19.cpp) | [LC 19 — Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | ✅ |
| [`lc-82.cpp`](linked-list/lc-82.cpp) | [LC 82 — Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | ✅ |
| [`cw-linked-lists-length-and-count.cpp`](linked-list/cw-linked-lists-length-and-count.cpp) | [Codewars — Linked Lists - Length & Count](https://www.codewars.com/kata/55beec7dd347078289000021) | ✅ |

## math

| File | Problem | Status |
|---|---|---|
| [`cf-4A.cpp`](math/cf-4A.cpp) | [CF 4A — Watermelon](https://codeforces.com/problemset/problem/4/A) | ✅ |
| [`cf-4A.ts`](math/cf-4A.ts) | [CF 4A — Watermelon](https://codeforces.com/problemset/problem/4/A) | ✅ |
| [`cf-50A.cpp`](math/cf-50A.cpp) | [CF 50A — Domino piling](https://codeforces.com/problemset/problem/50/A) | ✅ |
| [`cf-80A.cpp`](math/cf-80A.cpp) | [CF 80A — Panoramix's Prophecy](https://codeforces.com/problemset/problem/80/A) | ⚠️ |
| [`cf-sgu100.cpp`](math/cf-sgu100.cpp) | [CF acm.sgu 100 — A+B (acm.sgu.ru 100)](https://codeforces.com/problemsets/acmsguru/problem/99999/100) | ✅ |
| [`cf-151A.cpp`](math/cf-151A.cpp) | [CF 151A — Soft Drinking](https://codeforces.com/problemset/problem/151/A) | ✅ |
| [`cf-200B.cpp`](math/cf-200B.cpp) | [CF 200B — Drinks](https://codeforces.com/problemset/problem/200/B) | ✅ |
| [`cf-546A.cpp`](math/cf-546A.cpp) | [CF 546A — Soldier and Bananas](https://codeforces.com/problemset/problem/546/A) | ✅ |
| [`cf-758A.cpp`](math/cf-758A.cpp) | [CF 758A — Holiday Of Equality](https://codeforces.com/problemset/problem/758/A) | ✅ |
| [`cf-1335A.cpp`](math/cf-1335A.cpp) | [CF 1335A — Candies and Two Sisters](https://codeforces.com/problemset/problem/1335/A) | ✅ |
| [`cf-1367B.cpp`](math/cf-1367B.cpp) | [CF 1367B — Even Array](https://codeforces.com/problemset/problem/1367/B) | ✅ |
| [`cf-1409A.cpp`](math/cf-1409A.cpp) | [CF 1409A — Yet Another Two Integers Problem](https://codeforces.com/problemset/problem/1409/A) | ✅ |
| [`cf-1593B.cpp`](math/cf-1593B.cpp) | [CF 1593B — Make it Divisible by 25](https://codeforces.com/problemset/problem/1593/B) | ✅ |
| [`cf-1742A.cpp`](math/cf-1742A.cpp) | [CF 1742A — Sum](https://codeforces.com/problemset/problem/1742/A) | ✅ |
| [`cf-1772A.cpp`](math/cf-1772A.cpp) | [CF 1772A — A+B?](https://codeforces.com/problemset/problem/1772/A) | ✅ |
| [`cf-1807A.cpp`](math/cf-1807A.cpp) | [CF 1807A — Plus or Minus](https://codeforces.com/problemset/problem/1807/A) | ✅ |
| [`cf-1850A.cpp`](math/cf-1850A.cpp) | [CF 1850A — To My Critics](https://codeforces.com/problemset/problem/1850/A) | ✅ |
| [`cf-1989A.cpp`](math/cf-1989A.cpp) | [CF 1989A — Catch the Coin](https://codeforces.com/problemset/problem/1989/A) | ✅ |
| [`cf-1991A.cpp`](math/cf-1991A.cpp) | [CF 1991A — Maximize the Last Element](https://codeforces.com/problemset/problem/1991/A) | ✅ |
| [`cf-1999A.cpp`](math/cf-1999A.cpp) | [CF 1999A — A+B Again?](https://codeforces.com/problemset/problem/1999/A) | ✅ |
| [`cf-2044A.cpp`](math/cf-2044A.cpp) | [CF 2044A — Easy Problem](https://codeforces.com/problemset/problem/2044/A) | ✅ |
| [`cf-2110A.cpp`](math/cf-2110A.cpp) | [CF 2110A — Fashionable Array](https://codeforces.com/problemset/problem/2110/A) | ✅ |
| [`cf-2152A.cpp`](math/cf-2152A.cpp) | [CF 2152A — Increase or Smash](https://codeforces.com/problemset/problem/2152/A) | ✅ |
| [`cf-2164A.cpp`](math/cf-2164A.cpp) | [CF 2164A — Sequence Game](https://codeforces.com/problemset/problem/2164/A) | ✅ |
| [`cf-2166B.cpp`](math/cf-2166B.cpp) | [CF 2166B — Tab Closing](https://codeforces.com/problemset/problem/2166/B) | ✅ |
| [`cf-2167D.cpp`](math/cf-2167D.cpp) | [CF 2167D — Yet Another Array Problem](https://codeforces.com/problemset/problem/2167/D) | ✅ |
| [`cf-2175A.cpp`](math/cf-2175A.cpp) | [CF 2175A — Little Fairy's Painting](https://codeforces.com/problemset/problem/2175/A) | ✅ |
| [`cf-2179A.cpp`](math/cf-2179A.cpp) | [CF 2179A — Blackslex and Password](https://codeforces.com/problemset/problem/2179/A) | ✅ |
| [`cf-2184C.cpp`](math/cf-2184C.cpp) | [CF 2184C — Huge Pile](https://codeforces.com/problemset/problem/2184/C) | ✅ |
| [`cf-2185A.cpp`](math/cf-2185A.cpp) | [CF 2185A — Perfect Root](https://codeforces.com/problemset/problem/2185/A) | ✅ |
| [`cf-2193A.cpp`](math/cf-2193A.cpp) | [CF 2193A — DBMB and the Array](https://codeforces.com/problemset/problem/2193/A) | ✅ |
| [`cf-2209B.cpp`](math/cf-2209B.cpp) | [CF 2209B — Array](https://codeforces.com/problemset/problem/2209/B) | ⚠️ |
| [`cf-2227A.cpp`](math/cf-2227A.cpp) | [CF 2227A — Koshary](https://codeforces.com/problemset/problem/2227/A) | ✅ |
| [`cf-2236A.cpp`](math/cf-2236A.cpp) | [CF 2236A — Games on the Train](https://codeforces.com/problemset/problem/2236/A) | ✅ |
| [`cf-2236B.cpp`](math/cf-2236B.cpp) | [CF 2236B — Tatar TV Show](https://codeforces.com/problemset/problem/2236/B) | ✅ |
| [`cf-2241A.cpp`](math/cf-2241A.cpp) | [CF 2241A — Divide and Conquer](https://codeforces.com/problemset/problem/2241/A) | ✅ |
| [`lc-1281.cpp`](math/lc-1281.cpp) | [LC 1281 — Subtract the Product and Sum of Digits of an Integer](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/) | ✅ |
| [`lc-1390.cpp`](math/lc-1390.cpp) | [LC 1390 — Four Divisors](https://leetcode.com/problems/four-divisors/) | ✅ |
| [`lc-1979.cpp`](math/lc-1979.cpp) | [LC 1979 — Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/) | ✅ ⚡ |
| [`cw-beginner-series-1-school-paperwork.cpp`](math/cw-beginner-series-1-school-paperwork.cpp) | Codewars — Beginner Series #1 School Paperwork | ✅ |
| [`cw-beginner-series-4-cockroach.cpp`](math/cw-beginner-series-4-cockroach.cpp) | Codewars — Beginner Series #4 Cockroach | ✅ |
| [`cw-bouncing-balls.cpp`](math/cw-bouncing-balls.cpp) | Codewars — Bouncing Balls | ✅ |
| [`cw-collatz-conjecture-3n-plus-1.cpp`](math/cw-collatz-conjecture-3n-plus-1.cpp) | [Codewars — Collatz Conjecture (3n+1)](https://www.codewars.com/kata/577a6e90d48e51c55e000217) | ✅ |
| [`cw-count-by-x.cpp`](math/cw-count-by-x.cpp) | Codewars — Count by X | ✅ |
| [`cw-count-the-digit.cpp`](math/cw-count-the-digit.cpp) | Codewars — Count the Digit | ✅ |
| [`cw-deodorant-evaporator.cpp`](math/cw-deodorant-evaporator.cpp) | Codewars — Deodorant Evaporator | ✅ |
| [`cw-disarium-number-special-numbers-series-3.cpp`](math/cw-disarium-number-special-numbers-series-3.cpp) | Codewars — Disarium Number (Special Numbers Series #3) | ✅ ⚡ |
| [`cw-drying-potatoes.cpp`](math/cw-drying-potatoes.cpp) | Codewars — Drying Potatoes | ✅ |
| [`cw-find-the-nth-digit-of-a-number.cpp`](math/cw-find-the-nth-digit-of-a-number.cpp) | Codewars — Find the nth Digit of a Number | ✅ |
| [`cw-is-he-gonna-survive.cpp`](math/cw-is-he-gonna-survive.cpp) | Codewars — Is he gonna survive? | ✅ |
| [`cw-is-it-even.cpp`](math/cw-is-it-even.cpp) | Codewars — Is it even? | ✅ |
| [`cw-jumping-number.cpp`](math/cw-jumping-number.cpp) | Codewars — Jumping Number (Special Numbers Series #4) | ✅ |
| [`cw-multiples-of-3-or-5.cpp`](math/cw-multiples-of-3-or-5.cpp) | Codewars — Multiples of 3 or 5 | ✅ ⚡ |
| [`cw-number-of-decimal-digits.cpp`](math/cw-number-of-decimal-digits.cpp) | Codewars — Number of Decimal Digits | ✅ |
| [`cw-odd-or-even.cpp`](math/cw-odd-or-even.cpp) | Codewars — Odd or Even? | ✅ |
| [`cw-opposites-attract.cpp`](math/cw-opposites-attract.cpp) | Codewars — Opposites Attract | ✅ |
| [`cw-over-the-road.cpp`](math/cw-over-the-road.cpp) | Codewars — Over The Road | ✅ |
| [`cw-persistent-bugger.cpp`](math/cw-persistent-bugger.cpp) | [Codewars — Persistent Bugger.](https://www.codewars.com/kata/55bf01e5a717a0d57e0000ec) | ✅ |
| [`cw-playing-with-digits.cpp`](math/cw-playing-with-digits.cpp) | Codewars — Playing with digits | ✅ |
| [`cw-powers-of-2.cpp`](math/cw-powers-of-2.cpp) | Codewars — Powers of 2 | ✅ ⚡ |
| [`cw-predict-your-age.cpp`](math/cw-predict-your-age.cpp) | Codewars — Predict your age! | ✅ |
| [`cw-pythagorean-triple.cpp`](math/cw-pythagorean-triple.cpp) | [Codewars — Pythagorean Triple](https://en.wikipedia.org/wiki/Pythagorean_triple)) | ✅ |
| [`cw-quarter-of-the-year.cpp`](math/cw-quarter-of-the-year.cpp) | Codewars — Quarter of the year | ✅ ⚡ |
| [`cw-seconds-to-hours-and-minutes.cpp`](math/cw-seconds-to-hours-and-minutes.cpp) | Codewars — Seconds to hours and minutes (to_time) | ✅ |
| [`cw-simple-beads-count.cpp`](math/cw-simple-beads-count.cpp) | Codewars — Simple beads count | ✅ |
| [`cw-special-number.cpp`](math/cw-special-number.cpp) | Codewars — Special Number (Special Numbers Series #5) | ✅ |
| [`cw-square-every-digit.cpp`](math/cw-square-every-digit.cpp) | Codewars — Square Every Digit | ✅ |
| [`cw-sum-of-a-sequence.cpp`](math/cw-sum-of-a-sequence.cpp) | Codewars — Sum of a sequence | ✅ ⚡ |
| [`cw-sum-of-cubes.cpp`](math/cw-sum-of-cubes.cpp) | Codewars — Sum of Cubes | ✅ ⚡ |
| [`cw-sum-of-odd-numbers.cpp`](math/cw-sum-of-odd-numbers.cpp) | Codewars — Sum of odd numbers | ✅ ⚡ |
| [`cw-the-office-i-outed.cpp`](math/cw-the-office-i-outed.cpp) | Codewars — The Office I - Outed | ✅ |
| [`cw-tidy-number.cpp`](math/cw-tidy-number.cpp) | Codewars — Tidy Number (Special Numbers Series #9) | ⚠️ |
| [`cw-tortoise-racing.cpp`](math/cw-tortoise-racing.cpp) | [Codewars — Tortoise racing](https://www.codewars.com/kata/55e2adece53b4cdcb900006c) | ✅ |
| [`practice-digit-sum.cpp`](math/practice-digit-sum.cpp) | Practice — Sum of Digits | ✅ |
| [`practice-is-prime.cpp`](math/practice-is-prime.cpp) | Practice — Check if a Number is Prime | ✅ |
| [`practice-power.cpp`](math/practice-power.cpp) | Practice — Power Without pow() | ✅ ⚡ |

## matrix

| File | Problem | Status |
|---|---|---|
| [`cf-263A.cpp`](matrix/cf-263A.cpp) | [CF 263A — Beautiful Matrix](https://codeforces.com/problemset/problem/263/A) | ✅ |
| [`cf-1692C.cpp`](matrix/cf-1692C.cpp) | [CF 1692C — Where's the Bishop?](https://codeforces.com/problemset/problem/1692/C) | ✅ |
| [`cf-1996B.cpp`](matrix/cf-1996B.cpp) | [CF 1996B — Scale](https://codeforces.com/problemset/problem/1996/B) | ✅ |
| [`lc-867.cpp`](matrix/lc-867.cpp) | [LC 867 — Transpose Matrix](https://leetcode.com/problems/transpose-matrix/) | ✅ |
| [`lc-1260.cpp`](matrix/lc-1260.cpp) | [LC 1260 — Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/) | ✅ |
| [`lc-1572.cpp`](matrix/lc-1572.cpp) | [LC 1572 — Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/) | ✅ |
| [`lc-2946.cpp`](matrix/lc-2946.cpp) | [LC 2946 — Matrix Similarity After Cyclic Shifts](https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/) | ✅ |

## prefix-sum

| File | Problem | Status |
|---|---|---|
| [`cf-2193C.cpp`](prefix-sum/cf-2193C.cpp) | [CF 2193C — Replace and Sum](https://codeforces.com/problemset/problem/2193/C) | ✅ |
| [`lc-303.cpp`](prefix-sum/lc-303.cpp) | [LC 303 — Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) | ✅ ⚡ |
| [`lc-1653.cpp`](prefix-sum/lc-1653.cpp) | [LC 1653 — Minimum Deletions to Make String Balanced](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/) | ✅ |
| [`lc-2615.cpp`](prefix-sum/lc-2615.cpp) | [LC 2615 — Sum of Distances](https://leetcode.com/problems/sum-of-distances/) | ✅ |

## sliding-window

| File | Problem | Status |
|---|---|---|
| [`lc-3.cpp`](sliding-window/lc-3.cpp) | [LC 3 — Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ✅ ⚡ |
| [`lc-219.cpp`](sliding-window/lc-219.cpp) | [LC 219 — Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) | ✅ |

## sorting

| File | Problem | Status |
|---|---|---|
| [`cf-339A.cpp`](sorting/cf-339A.cpp) | [CF 339A — Helpful Maths](https://codeforces.com/problemset/problem/339/A) | ✅ |
| [`cf-1399A.cpp`](sorting/cf-1399A.cpp) | [CF 1399A — Remove Smallest](https://codeforces.com/problemset/problem/1399/A) | ✅ |
| [`cf-1760A.cpp`](sorting/cf-1760A.cpp) | [CF 1760A — Medium Number](https://codeforces.com/problemset/problem/1760/A) | ✅ |
| [`cf-1903A.cpp`](sorting/cf-1903A.cpp) | [CF 1903A — Halloumi Boxes](https://codeforces.com/problemset/problem/1903/A) | ✅ |
| [`cf-1946A.cpp`](sorting/cf-1946A.cpp) | [CF 1946A — Median of an Array](https://codeforces.com/problemset/problem/1946/A) | ✅ |
| [`cf-1970A1.cpp`](sorting/cf-1970A1.cpp) | [CF 1970A1 — Balanced Shuffle (Easy)](https://codeforces.com/problemset/problem/1970/A1) | ✅ |
| [`cf-2102B.cpp`](sorting/cf-2102B.cpp) | [CF 2102B — The Picky Cat](https://codeforces.com/problemset/problem/2102/B) | ⚠️ |
| [`cf-2167C.cpp`](sorting/cf-2167C.cpp) | [CF 2167C — Isamatdin and His Magic Wand!](https://codeforces.com/problemset/problem/2167/C) | ✅ |
| [`cf-2185C.cpp`](sorting/cf-2185C.cpp) | [CF 2185C — Shifted MEX](https://codeforces.com/problemset/problem/2185/C) | ✅ |
| [`lc-1200.cpp`](sorting/lc-1200.cpp) | [LC 1200 — Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/) | ✅ |
| [`lc-1984.cpp`](sorting/lc-1984.cpp) | [LC 1984 — Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/) | ✅ |
| [`lc-2418.cpp`](sorting/lc-2418.cpp) | [LC 2418 — Sort the People](https://leetcode.com/problems/sort-the-people/) | ✅ |
| [`lc-2784.cpp`](sorting/lc-2784.cpp) | [LC 2784 — Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good/) | ✅ ⚡ |
| [`cw-are-they-the-same.cpp`](sorting/cw-are-they-the-same.cpp) | Codewars — Are they the "same"? | ✅ |
| [`cw-nth-smallest-element-array-series-4.cpp`](sorting/cw-nth-smallest-element-array-series-4.cpp) | [Codewars — Nth Smallest Element (Array Series #4)](https://www.codewars.com/kata/5a512f6a80eba857280000fc) | ✅ ⚡ |
| [`cw-sum-of-two-lowest-positive-integers.cpp`](sorting/cw-sum-of-two-lowest-positive-integers.cpp) | Codewars — Sum of two lowest positive integers | ✅ ⚡ |

## stack

| File | Problem | Status |
|---|---|---|
| [`lc-85.cpp`](stack/lc-85.cpp) | [LC 85 — Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) | ✅ ⚡ |
| [`lc-150.cpp`](stack/lc-150.cpp) | [LC 150 — Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | ✅ |
| [`lc-636.cpp`](stack/lc-636.cpp) | [LC 636 — Exclusive Time of Functions](https://leetcode.com/problems/exclusive-time-of-functions/) | ✅ |
| [`lc-1544.cpp`](stack/lc-1544.cpp) | [LC 1544 — Make The String Great](https://leetcode.com/problems/make-the-string-great/) | ✅ |
| [`lc-1598.cpp`](stack/lc-1598.cpp) | [LC 1598 — Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder/) | ✅ |
| [`cw-directions-reduction.cpp`](stack/cw-directions-reduction.cpp) | Codewars — Directions Reduction | ✅ ⚡ |

## strings

| File | Problem | Status |
|---|---|---|
| [`cf-41A.cpp`](strings/cf-41A.cpp) | [CF 41A — Translation](https://codeforces.com/problemset/problem/41/A) | ✅ |
| [`cf-59A.cpp`](strings/cf-59A.cpp) | [CF 59A — Word](https://codeforces.com/problemset/problem/59/A) | ✅ |
| [`cf-61A.cpp`](strings/cf-61A.cpp) | [CF 61A — Ultra-Fast Mathematician](https://codeforces.com/problemset/problem/61/A) | ✅ |
| [`cf-71A.cpp`](strings/cf-71A.cpp) | [CF 71A — Way Too Long Words](https://codeforces.com/problemset/problem/71/A) | ✅ |
| [`cf-96A.cpp`](strings/cf-96A.cpp) | [CF 96A — Football](https://codeforces.com/problemset/problem/96/A) | ✅ |
| [`cf-110A.cpp`](strings/cf-110A.cpp) | [CF 110A — Nearly Lucky Number](https://codeforces.com/problemset/problem/110/A) | ✅ |
| [`cf-112A.cpp`](strings/cf-112A.cpp) | [CF 112A — Petya and Strings](https://codeforces.com/problemset/problem/112/A) | ✅ |
| [`cf-118A.cpp`](strings/cf-118A.cpp) | [CF 118A — String Task](https://codeforces.com/problemset/problem/118/A) | ✅ |
| [`cf-266A.cpp`](strings/cf-266A.cpp) | [CF 266A — Stones on the Table](https://codeforces.com/problemset/problem/266/A) | ✅ |
| [`cf-281A.cpp`](strings/cf-281A.cpp) | [CF 281A — Word Capitalization](https://codeforces.com/problemset/problem/281/A) | ✅ |
| [`cf-734A.cpp`](strings/cf-734A.cpp) | [CF 734A — Anton and Danik](https://codeforces.com/problemset/problem/734/A) | ✅ |
| [`cf-1367A.cpp`](strings/cf-1367A.cpp) | [CF 1367A — Short Substrings](https://codeforces.com/problemset/problem/1367/A) | ✅ |
| [`cf-1520A.cpp`](strings/cf-1520A.cpp) | [CF 1520A — Do Not Be Distracted!](https://codeforces.com/problemset/problem/1520/A) | ✅ |
| [`cf-1619A.cpp`](strings/cf-1619A.cpp) | [CF 1619A — Square String?](https://codeforces.com/problemset/problem/1619/A) | ✅ |
| [`cf-1676A.cpp`](strings/cf-1676A.cpp) | [CF 1676A — Lucky?](https://codeforces.com/problemset/problem/1676/A) | ✅ |
| [`cf-1703A.cpp`](strings/cf-1703A.cpp) | [CF 1703A — YES or YES?](https://codeforces.com/problemset/problem/1703/A) | ✅ |
| [`cf-1722A.cpp`](strings/cf-1722A.cpp) | [CF 1722A — Spell Check](https://codeforces.com/problemset/problem/1722/A) | ✅ |
| [`cf-1791A.cpp`](strings/cf-1791A.cpp) | [CF 1791A — Codeforces Checking](https://codeforces.com/problemset/problem/1791/A) | ✅ |
| [`cf-1818A.cpp`](strings/cf-1818A.cpp) | [CF 1818A — Politics](https://codeforces.com/problemset/problem/1818/A) | ✅ |
| [`cf-1820A.cpp`](strings/cf-1820A.cpp) | [CF 1820A — Yura's New Name](https://codeforces.com/problemset/problem/1820/A) | ✅ |
| [`cf-1894A.cpp`](strings/cf-1894A.cpp) | [CF 1894A — Secret Sport](https://codeforces.com/problemset/problem/1894/A) | ✅ |
| [`cf-1915D.cpp`](strings/cf-1915D.cpp) | [CF 1915D — Unnatural Language Processing](https://codeforces.com/problemset/problem/1915/D) | ✅ |
| [`cf-1926A.cpp`](strings/cf-1926A.cpp) | [CF 1926A — Vlad and the Best of Five](https://codeforces.com/problemset/problem/1926/A) | ✅ |
| [`cf-1971B.cpp`](strings/cf-1971B.cpp) | [CF 1971B — Different String](https://codeforces.com/problemset/problem/1971/B) | ✅ |
| [`cf-1976A.cpp`](strings/cf-1976A.cpp) | [CF 1976A — Verify Password](https://codeforces.com/problemset/problem/1976/A) | ✅ ⚡ |
| [`cf-1985A-2.cpp`](strings/cf-1985A-2.cpp) | [CF 1985A — Creating Words](https://codeforces.com/problemset/problem/1985/A) | ✅ |
| [`cf-1985A.cpp`](strings/cf-1985A.cpp) | [CF 1985A — Creating Words](https://codeforces.com/problemset/problem/1985/A) | ✅ |
| [`cf-1997A.cpp`](strings/cf-1997A.cpp) | [CF 1997A — Strong Password](https://codeforces.com/problemset/problem/1997/A) | ✅ |
| [`cf-2003A.cpp`](strings/cf-2003A.cpp) | [CF 2003A — Turtle and Good Strings](https://codeforces.com/problemset/problem/2003/A) | ✅ |
| [`cf-2044B.cpp`](strings/cf-2044B.cpp) | [CF 2044B — Normal Problem](https://codeforces.com/problemset/problem/2044/B) | ✅ |
| [`cf-2110B.cpp`](strings/cf-2110B.cpp) | [CF 2110B — Down with Brackets](https://codeforces.com/problemset/problem/2110/B) | ✅ |
| [`cf-2125A.cpp`](strings/cf-2125A.cpp) | [CF 2125A — Difficult Contest](https://codeforces.com/problemset/problem/2125/A) | ✅ |
| [`cf-2132A.cpp`](strings/cf-2132A.cpp) | [CF 2132A — Homework](https://codeforces.com/problemset/problem/2132/A) | ✅ |
| [`cf-2182A.cpp`](strings/cf-2182A.cpp) | [CF 2182A — New Year String](https://codeforces.com/problemset/problem/2182/A) | ✅ |
| [`cf-2192A.cpp`](strings/cf-2192A.cpp) | [CF 2192A — String Rotation Game](https://codeforces.com/problemset/problem/2192/A) | ✅ ⚡ |
| [`cf-2227B.cpp`](strings/cf-2227B.cpp) | [CF 2227B — Party Monster](https://codeforces.com/problemset/problem/2227/B) | ✅ |
| [`cf-2241C.cpp`](strings/cf-2241C.cpp) | [CF 2241C — RemovevomeR](https://codeforces.com/problemset/problem/2241/C) | ✅ |
| [`cf-2244A.cpp`](strings/cf-2244A.cpp) | [CF 2244A — Iskander and Drawings](https://codeforces.com/problemset/problem/2244/A) | ✅ |
| [`lc-521.cpp`](strings/lc-521.cpp) | [LC 521 — Longest Uncommon Subsequence I](https://leetcode.com/problems/longest-uncommon-subsequence-i/) | ✅ |
| [`lc-824.cpp`](strings/lc-824.cpp) | [LC 824 — Goat Latin](https://leetcode.com/problems/goat-latin/) | ✅ |
| [`lc-1556.cpp`](strings/lc-1556.cpp) | [LC 1556 — Thousand Separator](https://leetcode.com/problems/thousand-separator/) | ✅ |
| [`lc-1576.cpp`](strings/lc-1576.cpp) | [LC 1576 — Replace All ?'s to Avoid Consecutive Repeating Characters](https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/) | ✅ |
| [`lc-1945.cpp`](strings/lc-1945.cpp) | [LC 1945 — Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/) | ✅ |
| [`lc-1957.cpp`](strings/lc-1957.cpp) | [LC 1957 — Delete Characters to Make Fancy String](https://leetcode.com/problems/delete-characters-to-make-fancy-string/) | ✅ |
| [`lc-1967.cpp`](strings/lc-1967.cpp) | [LC 1967 — Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/) | ✅ |
| [`lc-1974.cpp`](strings/lc-1974.cpp) | [LC 1974 — Minimum Time to Type Word Using Special Typewriter](https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/) | ✅ |
| [`lc-2399.cpp`](strings/lc-2399.cpp) | [LC 2399 — Check Distances Between Same Letters](https://leetcode.com/problems/check-distances-between-same-letters/) | ✅ |
| [`lc-2452.cpp`](strings/lc-2452.cpp) | [LC 2452 — Words Within Two Edits of Dictionary](https://leetcode.com/problems/words-within-two-edits-of-dictionary/) | ✅ |
| [`lc-3794.cpp`](strings/lc-3794.cpp) | [LC 3794 — Reverse String Prefix](https://leetcode.com/problems/reverse-string-prefix/) | ✅ |
| [`cw-abbreviate-a-two-word-name.cpp`](strings/cw-abbreviate-a-two-word-name.cpp) | Codewars — Abbreviate a Two Word Name | ✅ |
| [`cw-all-star-code-challenge-15.cpp`](strings/cw-all-star-code-challenge-15.cpp) | Codewars — All Star Code Challenge #15 | ✅ |
| [`cw-all-star-code-challenge-18.cpp`](strings/cw-all-star-code-challenge-18.cpp) | Codewars — All Star Code Challenge #18 | ✅ |
| [`cw-all-star-code-challenge-3.cpp`](strings/cw-all-star-code-challenge-3.cpp) | Codewars — All Star Code Challenge #3 | ✅ ⚡ |
| [`cw-alternating-case.cpp`](strings/cw-alternating-case.cpp) | Codewars — altERnaTIng cAsE <=> ALTerNAtiNG CaSe | ✅ ⚡ |
| [`cw-arithmetic-progression.cpp`](strings/cw-arithmetic-progression.cpp) | Codewars — Arithmetic progression | ✅ |
| [`cw-array-of-strings-to-numbers.cpp`](strings/cw-array-of-strings-to-numbers.cpp) | Codewars — Convert an array of strings to array of numbers | ✅ |
| [`cw-build-tower.cpp`](strings/cw-build-tower.cpp) | Codewars — Build Tower | ✅ |
| [`cw-bumps-in-the-road.cpp`](strings/cw-bumps-in-the-road.cpp) | Codewars — Bumps in the Road | ✅ |
| [`cw-cat-and-mouse-easy-version.cpp`](strings/cw-cat-and-mouse-easy-version.cpp) | Codewars — Cat and Mouse - Easy Version | ✅ ⚡ |
| [`cw-compare-strings-by-sum-of-chars.cpp`](strings/cw-compare-strings-by-sum-of-chars.cpp) | [Codewars — Compare Strings by Sum of Chars](https://www.codewars.com/kata/576bb3c4b1abc497ec000065) | ⚠️ |
| [`cw-convert-an-array-of-strings-to-array-of-numbers.cpp`](strings/cw-convert-an-array-of-strings-to-array-of-numbers.cpp) | Codewars — Convert an array of strings to array of numbers | ✅ |
| [`cw-correct-the-mistakes-of-the-character-recognition-software.cpp`](strings/cw-correct-the-mistakes-of-the-character-recognition-software.cpp) | Codewars — Correct the mistakes of the character recognition software | ✅ |
| [`cw-count-letters-and-digits.cpp`](strings/cw-count-letters-and-digits.cpp) | Codewars — Count letters and digits | ✅ |
| [`cw-drone-fly-by.cpp`](strings/cw-drone-fly-by.cpp) | Codewars — Drone Fly-By | ✅ |
| [`cw-exes-and-ohs.cpp`](strings/cw-exes-and-ohs.cpp) | Codewars — Exes and Ohs | ✅ |
| [`cw-filter-long-words.cpp`](strings/cw-filter-long-words.cpp) | Codewars — Filter Long Words | ✅ |
| [`cw-filter-the-number.cpp`](strings/cw-filter-the-number.cpp) | Codewars — Filter the number | ✅ |
| [`cw-find-the-vowels.cpp`](strings/cw-find-the-vowels.cpp) | Codewars — Find the vowels | ✅ |
| [`cw-fix-string-case.cpp`](strings/cw-fix-string-case.cpp) | Codewars — Fix string case | ✅ |
| [`cw-friend-or-foe.cpp`](strings/cw-friend-or-foe.cpp) | Codewars — Friend or Foe? | ✅ |
| [`cw-get-the-middle-character.cpp`](strings/cw-get-the-middle-character.cpp) | Codewars — Get the Middle Character | ✅ |
| [`cw-help-bob-count-letters-and-digits.cpp`](strings/cw-help-bob-count-letters-and-digits.cpp) | Codewars — Help Bob count letters and digits. | ✅ |
| [`cw-highest-and-lowest.cpp`](strings/cw-highest-and-lowest.cpp) | Codewars — Highest and Lowest | ✅ |
| [`cw-highest-scoring-word.cpp`](strings/cw-highest-scoring-word.cpp) | Codewars — Highest Scoring Word | ✅ ⚡ |
| [`cw-indexed-capitalization.cpp`](strings/cw-indexed-capitalization.cpp) | Codewars — Indexed capitalization | ✅ |
| [`cw-multiplication-table-for-number.cpp`](strings/cw-multiplication-table-for-number.cpp) | Codewars — Multiplication table for number | ✅ |
| [`cw-numbers-to-letters.cpp`](strings/cw-numbers-to-letters.cpp) | [Codewars — Numbers to Letters](https://www.codewars.com/kata/numbers-to-letters) | ✅ |
| [`cw-odd-even-string-sort.cpp`](strings/cw-odd-even-string-sort.cpp) | Codewars — Odd-Even String Sort | ✅ |
| [`cw-padded-numbers.cpp`](strings/cw-padded-numbers.cpp) | Codewars — Substituting Variables Into Strings: Padded Numbers | ✅ |
| [`cw-printer-errors.cpp`](strings/cw-printer-errors.cpp) | Codewars — Printer Errors | ✅ |
| [`cw-remove-anchor-from-url.cpp`](strings/cw-remove-anchor-from-url.cpp) | Codewars — Remove anchor from URL | ✅ |
| [`cw-remove-exclamation-marks.cpp`](strings/cw-remove-exclamation-marks.cpp) | Codewars — Remove exclamation marks | ✅ |
| [`cw-replace-all-vowels-to-exclamation-mark.cpp`](strings/cw-replace-all-vowels-to-exclamation-mark.cpp) | Codewars — Exclamation marks series #11: Replace all vowel to exclamation mark in the sentence | ✅ |
| [`cw-replace-with-alphabet-position.cpp`](strings/cw-replace-with-alphabet-position.cpp) | Codewars — Replace With Alphabet Position | ✅ |
| [`cw-reverse-words.cpp`](strings/cw-reverse-words.cpp) | Codewars — Reverse words | ✅ ⚡ |
| [`cw-simple-string-characters.cpp`](strings/cw-simple-string-characters.cpp) | [Codewars — Simple string characters](https://www.codewars.com/kata/5a29a0898f27f2d9c9000058) | ✅ |
| [`cw-sort-and-star.cpp`](strings/cw-sort-and-star.cpp) | Codewars — Sort and Star | ✅ ⚡ |
| [`cw-substituting-variables-into-strings-padded-numbers.cpp`](strings/cw-substituting-variables-into-strings-padded-numbers.cpp) | Codewars — Substituting Variables Into Strings: Padded Numbers | ✅ |
| [`cw-switcheroo.cpp`](strings/cw-switcheroo.cpp) | Codewars — Switcheroo | ✅ |
| [`cw-testing-1-2-3.cpp`](strings/cw-testing-1-2-3.cpp) | Codewars — Testing 1-2-3 | ✅ |
| [`cw-vaporcode.cpp`](strings/cw-vaporcode.cpp) | Codewars — V  A  P  O  R  C  O  D  E | ✅ |
| [`cw-vowel-count.cpp`](strings/cw-vowel-count.cpp) | Codewars — Vowel Count | ✅ |
| [`practice-capitalize-words.cpp`](strings/practice-capitalize-words.cpp) | Practice — Capitalize Every Word | ✅ |

## templates

| File | Problem | Status |
|---|---|---|
| [`lc-template.cpp`](templates/lc-template.cpp) | Owner's LeetCode template | ✅ |

## trees

| File | Problem | Status |
|---|---|---|
| [`cf-115A.cpp`](trees/cf-115A.cpp) | [CF 115A — Party](https://codeforces.com/problemset/problem/115/A) | ✅ ⚡ |
| [`cf-1057A.cpp`](trees/cf-1057A.cpp) | [CF 1057A — Bmail Computer Network](https://codeforces.com/problemset/problem/1057/A) | ✅ |
| [`cf-1900C.cpp`](trees/cf-1900C.cpp) | [CF 1900C — Anji's Binary Tree](https://codeforces.com/problemset/problem/1900/C) | ✅ |
| [`cf-2238C.cpp`](trees/cf-2238C.cpp) | [CF 2238C — Village Guilds](https://codeforces.com/problemset/problem/2238/C) | ✅ |
| [`lc-314.cpp`](trees/lc-314.cpp) | [LC 314 — Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/) | ⚠️ |
| [`lc-865.cpp`](trees/lc-865.cpp) | [LC 865 — Smallest Subtree with all the Deepest Nodes](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/) | ✅ |
| [`lc-1161.cpp`](trees/lc-1161.cpp) | [LC 1161 — Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/) | ✅ |
| [`lc-1339.cpp`](trees/lc-1339.cpp) | [LC 1339 — Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/) | ✅ |
| [`lc-1382.cpp`](trees/lc-1382.cpp) | [LC 1382 — Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/) | 🧩 |

## two-pointers

| File | Problem | Status |
|---|---|---|
| [`cf-2227D.cpp`](two-pointers/cf-2227D.cpp) | [CF 2227D — Palindromex](https://codeforces.com/problemset/problem/2227/D) | 🧩 |
| [`lc-3634.cpp`](two-pointers/lc-3634.cpp) | [LC 3634 — Minimum Removals to Balance Array](https://leetcode.com/problems/minimum-removals-to-balance-array/) | ✅ |
