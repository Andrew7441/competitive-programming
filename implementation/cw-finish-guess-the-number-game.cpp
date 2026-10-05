// Codewars — Finish Guess the Number Game
// Topic: implementation | Tags: design, classes, exceptions
// Complexity (yours): O(1) per guess, O(1) space

/*
You are creating a game where the user has to guess the correct number. But there is a limit of
how many guesses the user can do.

- If the user tries to guess more than the limit, the function should throw an error.
- If the user guess is right it should return true.
- If the user guess is wrong it should return false and lose a life.
*/

#include <stdexcept>

class Guesser
{
public:
    Guesser(int number, int lives)
      : number(number), lives(lives)
    { }
    
    bool guess(int n)
    {
        if (lives <= 0) {
            throw std::runtime_error("No lives left"); // learned this new 
            //throw std::exception(); // this works too
        }
        
        if (n == number) {
            return true;
        }else {
            --lives;
            return false;
        }
    }
    
private:
    int number, lives;
};

/*
💭 First Idea: keep number and lives as members; throw when no lives remain, otherwise compare.
🧩 Key Property / Invariant: the lives check must come BEFORE comparing the guess.
✅ Key insight: std::runtime_error("msg") (from <stdexcept>) is the standard way to signal a failure.
🔁 Recognition cue for next time: "throw an error when ..." -> throw std::runtime_error / std::invalid_argument.
⏱  Speed fix for next time: n/a — straightforward state + guard clause.
🛠  Review: correct; O(1) → Already optimal.
*/
