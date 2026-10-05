// Codewars — Is he gonna survive?
// Topic: math | Tags: division
// Complexity (yours): O(1)

/*
A hero is on his way to the castle to complete his mission. However, he's been told that the castle is surrounded with a couple of powerful dragons! each dragon takes 2 bullets to be defeated, our hero has no idea how many bullets he should carry.. Assuming he's gonna grab a specific given number of bullets and move forward to fight another specific given number of dragons, will he survive?

Return true if yes, false otherwise :)
*/

bool hero(int bullets, int dragons) {
  return bullets / 2 >= dragons;
}

/*
💭 First Idea: bullets / 2 ≥ dragons.
🧩 Key Property / Invariant: Each dragon needs 2 bullets: survive ⇔ bullets ≥ 2·dragons.
✅ Key insight: Integer division handles odd bullets correctly.
🔁 Recognition cue for next time: "k items per target" -> total ≥ k·targets.
⏱  Speed fix for next time: Fine as is.
🛠  Review: correct; O(1) — Already optimal.
*/
