// Codewars — Highest Scoring Word
// Topic: strings | Tags: hashing
// Complexity (yours): O(n) time, O(1) extra space
// From: Codewars/Functions 2.md — section "Function return the highest scoring word in a string of words."
/*
Kata description:
Given a string of words, find the highest scoring word. Each letter scores by its position in the alphabet: a = 1, b = 2, c = 3, ...
Return the highest scoring word as a string. If two words score the same, return the word that appears earliest in the original string. All letters are lowercase and all inputs are valid.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

std::unordered_map<char, int> charMap = { //declared a map so we can refer to 
    {'a', 1},
    {'b', 2},
    {'c', 3},
    {'d', 4},
    {'e', 5},
    {'f', 6},
    {'g', 7},
    {'h', 8},
    {'i', 9},
    {'j', 10},
    {'k', 11},
    {'l', 12},
    {'m', 13},
    {'n', 14},
    {'o', 15},
    {'p', 16},
    {'q', 17},
    {'r', 18},
    {'s', 19},
    {'t', 20},
    {'u', 21},
    {'v', 22},
    {'w', 23},
    {'x', 24},
    {'y', 25},
    {'z', 26}
};

int countOfWord(const std::string &word) {
    int sum = 0;
    for (char c : word) {
        auto it = charMap.find(c);
        if (it != charMap.end()) {
            sum += it->second;
        }
    }
    return sum;
}

std::string highestScoringWord(const std::string &str) {
    int maxScore = 0;  //keep track of maximum score encounter
    std::string maxWord; //store highest score

    std::istringstream iss(str); 
    std::string word;
    while (iss >> word) { // >> iss reads and assigns words to word 
        int score = countOfWord(word); // keep the score of each word from the function
        if (score > maxScore) { // if score larger than max score 
            maxScore = score; //update max score
            maxWord = word; // then assign that word into max word then
        }
    }

    return maxWord; //return the max word
}

// ===================== ⚡ Optimized =====================
// Same O(n), simpler: a letter's score is c - 'a' + 1, so the 26-entry hash map is unnecessary.
namespace optimized {
std::string highestScoringWord(const std::string &str) {
  std::istringstream iss(str);
  std::string word, best;
  int bestScore = -1;
  while (iss >> word) {
    int score = 0;
    for (char c : word) score += c - 'a' + 1;
    if (score > bestScore) { bestScore = score; best = word; }  // strict > keeps the earliest word on ties
  }
  return best;
}
}

/*
💭 First Idea: Split words with istringstream, score each via a char->int map, keep the max.
🧩 Key Property / Invariant: Strict > keeps the first word among equal scores.
✅ Key insight: Letter value = c - 'a' + 1; no map needed.
🔁 Recognition cue for next time: "alphabet position" -> c - 'a' + 1.
⏱  Speed fix for next time: Avoid building lookup maps for things that are plain arithmetic on chars.
🛠  Review: correct; O(n) -> simpler O(n) (no hash map).
*/
