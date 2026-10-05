// Codewars — Build Tower
// Topic: strings | Tags: pattern
// Complexity (yours): O(n^2) time and space (output size)
// From: Codewars/Functions 2.md — section "Function to build a pyramid based on input floors"
/*
Kata description:
Build a pyramid-shaped tower, as an array/list of strings, given a positive integer number of floors. A tower block is represented with "*".
For example, a tower with 3 floors looks like this:
[
  "  *  ",
  " *** ",
  "*****"
]
*/

#include <vector>
#include <string>

std::vector<std::string> towerBuilder(unsigned nFloors) {
    std::vector<std::string> result; 

    for (unsigned row = 0; row < nFloors; ++row) {
        std::string blanks(nFloors - row - 1, ' '); // Calculating the number of spaces needed before the stars.
        std::string stars(2 * row + 1, '*'); //calculating number of stars for each row
        result.push_back(blanks + stars + blanks); //pushback everything into its place
    }
    return result;
}
//Build a pyramid-shaped tower, as an array/list of strings, 
//given a positive integer number of floors.
// A tower block is represented with "*" character.

//For example, a tower with 3 floors looks like this:

//[
//  "  *  ",
//  " *** ", 
//  "*****"
//]

/*
💭 First Idea: Row r has (n - r - 1) blanks, (2r + 1) stars, then the same blanks.
🧩 Key Property / Invariant: Every row has total width 2n - 1.
✅ Key insight: The string(count, ch) constructor builds each part directly.
🔁 Recognition cue for next time: "draw a pyramid/pattern" -> derive counts per row as formulas of the row index.
⏱  Speed fix for next time: Use std::string(k, c) instead of loops for repeated characters.
🛠  Review: correct; O(n^2) = output size -> Already optimal.
*/
