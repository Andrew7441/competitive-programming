// Codewars — Persistent Bugger.
// https://www.codewars.com/kata/55bf01e5a717a0d57e0000ec
// Topic: math | Tags: digits, simulation
// Complexity (yours): O(steps * digits) time, O(1) space
// From: Codewars/Functions 2.md — section "Function Multiplicative Persistence"
/*
Kata description:
Write a function persistence that takes a positive parameter num and returns its multiplicative persistence: the number of times you must multiply the digits of num until you reach a single digit.
For example (Input --> Output): 39 --> 3 (because 3*9 = 27, 2*7 = 14, 1*4 = 4 and 4 has only one digit, there are 3 multiplications); 999 --> 4; 4 --> 0.
*/

int Persist( int value )
{
  int count = 0;  // number of times we multiplied all digits together

  while( value > 9 )  // loop until it has only 1 digit remaining
  {
    int temp = 1;

    do
    {
      temp *= (value % 10);  // multiply 'temp' by the low digit
      value /= 10;    // drop the low digit
    }while(value > 0);  // loop until no digits remaining

    value = temp;  // 'temp' is all digits multiplied together.  Put back in value
    ++count;
  }
  return count;
}
//explained thoroughly:
//Multiplicative Persistence: This is a fancy term! It means we’ll keep multiplying the digits of our number until we get a single-digit result. For example:
//If our number is 123, we multiply 1 × 2 × 3 = 6.
//If our number is 4567, we multiply 4 × 5 × 6 × 7 = 840.
//We keep doing this until we get a single-digit result.
//The Code: Let’s look at the code you provided. It’s like a recipe for solving our puzzle. Here’s what each part does:
//int Persist(int value): This is our special function. It takes a positive number (our “num”) as input and gives us the answer (how many times we need to multiply its digits).
//int count = 0;: We start with zero times because we haven’t done any multiplication yet.
//while (value > 9): This is our loop. We keep going until our number has only one digit left (which means it’s less than or equal to 9).
//Inside the loop:
//int temp = 1;: We create a temporary number called “temp.” It starts with 1 because multiplying by 1 doesn’t change anything.
//do { ... } while (value > 0);: This is another loop inside our big loop. It keeps going until our number has no more digits left.
//Inside this smaller loop:
//temp *= (value % 10);: We take the last digit of our number (using % 10) and multiply it with our temporary number “temp.”
//value /= 10;: We drop the last digit from our original number.
//We keep doing this until there are no more digits left.
//value = temp;: Now our original number becomes the result of all the multiplications we did (our “temp” number).
//++count;: We count how many times we did this process (how many loops we went through).
//Finally, we return the “count” as our answer!

/*
💭 First Idea: While value > 9, multiply its digits (via %10, /10) and count the rounds.
🧩 Key Property / Invariant: The digit product is always smaller than the number (for >= 10), so it terminates quickly (at most ~11 rounds).
✅ Key insight: Plain simulation is optimal; digit extraction with % 10 and / 10.
🔁 Recognition cue for next time: "repeat an operation until one digit" -> while (x > 9) loop with a counter.
⏱  Speed fix for next time: Use long long for the input to match the kata signature.
🛠  Review: correct; O(steps*digits) -> Already optimal.
*/
