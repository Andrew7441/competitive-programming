// Codewars — Printer Errors
// Topic: strings | Tags: counting
// Complexity (yours): O(n) time, O(1) extra space

/*
In a factory a printer prints labels for boxes. For one kind of boxes the printer has to use
colors which, for the sake of simplicity, are named with letters from `a to m`.

The colors used by the printer are recorded in a control string. For example a "good" control
string would be `aaabbbbhaijjjm` meaning that the printer used three times color a, four times
color b, one time color h then one time color a...

Sometimes there are problems: lack of colors, technical malfunction and a "bad" control string
is produced e.g. `aaaxbbbbyyhwawiwjjjwwm` with letters not from `a to m`.

You have to write a function `printer_error` which given a string will return the error rate of
the printer as a **string** representing a rational whose numerator is the number of errors and
the denominator the length of the control string. Don't reduce this fraction to a simpler
expression.

The string has a length greater or equal to one and contains only letters from `a` to `z`.

Examples:
s="aaabbbbhaijjjm"
printer_error(s) => "0/14"

s="aaaxbbbbyyhwawiwjjjwwm"
printer_error(s) => "8/22"
*/

#include <string> // added: std::string / std::to_string (missing in the original note)

// Attempt 1 (August 2024)
class Printer
{
public:
    static std::string printerError(const std::string &s){
      int error = 0;
      
      for(char i : s){
        if(i<'a' or i > 'm'){
          error++;
        }
      }     
      return std::to_string(error) + '/' + std::to_string(s.size());
    }
};

// Attempt 2 (March 4, 2025)
namespace attempt2 {
class Printer
{
public:
    static std::string printerError(const std::string &s){
      int error = 0;
      
      for(char c: s){
        if(c <'a' or c > 'm')
          error++;
      }
      
      return std::to_string(error) + "/" + std::to_string(s.size());

    }
};
} // namespace attempt2

/*
💭 First Idea: count characters outside 'a'..'m' and print "errors/length".
🧩 Key Property / Invariant: a character is an error iff it is > 'm' (input is only lowercase letters).
✅ Key insight: character ranges compare like numbers ('a' < 'm'), so a range check is one comparison pair.
🔁 Recognition cue for next time: "count chars matching a rule" -> one loop / std::count_if.
⏱  Speed fix for next time: std::count_if(s.begin(), s.end(), [](char c){ return c > 'm'; }).
🛠  Review: correct (both attempts identical in logic); O(n) → Already optimal.
*/
