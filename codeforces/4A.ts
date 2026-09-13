import * as fs from "fs";

const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);

function solve() {
    let a = Number(input);
    console.log(a % 2 === 0 && a > 2 ? "YES" : "NO");
}

solve();

/*
💭 First Idea
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱ Speed fix for next time
*/