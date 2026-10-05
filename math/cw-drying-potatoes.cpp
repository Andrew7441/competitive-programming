// Codewars — Drying Potatoes
// Topic: math | Tags: percentages, integer-arithmetic
// Complexity (yours): O(1) time, O(1) space

/*
Write function potatoes with

int parameter p0 - initial percent of water-
int parameter w0 - initial weight -
int parameter p1 - final percent of water -
potatoes should return the final weight coming out of the oven w1 truncated as an int.

Example:
potatoes(99, 100, 98) --> 50
*/

using namespace std;

int potatoes(int p0, int w0, int p1)
{
    return w0 * (100 - p0) / (100 - p1);
}

/*
💭 First Idea: dry mass is conserved: w0·(100-p0) = w1·(100-p1), solve for w1.
🧩 Key Property / Invariant: the non-water part never changes while drying.
✅ Key insight: multiply before dividing in integers — exact floor, no floating-point error (the famous trap of this kata).
🔁 Recognition cue for next time: "percent of X changes, find new total" -> the OTHER part is invariant.
⏱  Speed fix for next time: w0·(100-p0) ≤ 1e2·w0, fits int for the kata limits; use long long if w0 can be large.
🛠  Review: correct; O(1) → Already optimal.
*/
