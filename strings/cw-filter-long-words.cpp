// Codewars — Filter Long Words
// Topic: strings | Tags: parsing, stringstream
// Complexity (yours): O(len) time, O(len) space (both attempts)
// Merged: Attempt 1 from Codewars/Functions August 2024.md; Attempt 2 from Codewars/2025/February.md

/*
Write a function that takes a string and an integer `n` as parameters and returns a list of all
words that are longer than `n`.

Example:
* With input "The quick brown fox jumps over the lazy dog", 4
* Return ['quick', 'brown', 'jumps']
*/

#include <vector>
#include <string>
#include <sstream>

// ---------- Attempt 1 (Functions August 2024) ----------
std::vector<std::string> filter_long_words(const std::string& sentence, int n) {
    std::vector<std::string> res;
    std::istringstream stream(sentence);
    std::string word;
    
    while (stream >> word) {
        if (word.length() > n) {
            res.push_back(word);
        }
    }
    
    return res;
}

// ---------- Attempt 2 (February 2025) ----------
namespace attempt2 {  // (wrapper added in merge so all attempts compile in one file)
std::vector<std::string> filter_long_words(const std::string& sentence, int n) {
    std::vector<std::string> res;
    std::istringstream stream(sentence);
    std::string word;
    
    while (stream >> word) {
        if (word.length() > n) {
            res.push_back(word);
        }
    }
    
    return res;
}
}  // namespace attempt2

/*
💭 First Idea: Split the sentence with istringstream >> word and keep words with length > n (identical code both times).
🧩 Key Property / Invariant: operator>> skips any whitespace, so multiple spaces are handled for free.
✅ Key insight: istringstream is the idiomatic C++ "split on whitespace".
🔁 Recognition cue for next time: "words of a sentence" -> istringstream loop.
⏱  Speed fix for next time: Compare (int)word.length() > n to avoid the signed/unsigned warning.
🛠  Review: Attempt 1 correct, Attempt 2 correct; O(len) — Already optimal.
*/
