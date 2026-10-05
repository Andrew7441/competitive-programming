// Codeforces 4A — Watermelon
// https://codeforces.com/problemset/problem/4/A
// Topic: math | Tags: parity
// Complexity (yours): O(1) time, O(1) space
import * as fs from "fs";

const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);

function solve() {
    let a = Number(input);
    console.log(a % 2 === 0 && a > 2 ? "YES" : "NO");
}

solve();

/*
💭 First Idea: Check w is even and w > 2.
🧩 Key Property / Invariant: Two even parts sum to an even number; each part must be >= 2.
✅ Key insight: w=2 is the only even number that fails.
🔁 Recognition cue for next time: 'Split into two even parts' -> parity + edge case.
⏱ Speed fix for next time: Use Number(input[0]) - Number(input) only works because the array has one element.
🛠  Review: correct; Already optimal.
*/