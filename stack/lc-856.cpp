#include <bits/stdc++.h>
using namespace std;

/*
856. Score of Parentheses
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:
- "()" has score 1.
- AB has score A + B, where A and B are balanced parentheses strings.
- (A) has score 2 * A, where A is a balanced parentheses string.

Example 1:

Input: s = "()"
Output: 1

Example 2:

Input: s = "(())"
Output: 2

Example 3:

Input: s = "()()"
Output: 2
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(const auto& c : s) {
            if(c == '(') 
                st.push(0);
            else {
                int inner = st.top();
                st.pop();

                int score = (inner == 0 ? 1 : 2 * inner);
                
                int x = st.top();
                st.pop();
                
                st.push(x + score);
            }
        }

        return st.top();
    }
};

int main() {
    Solution S;
    std::string s = "(())";

    std::cout << S.scoreOfParentheses(s) << '\n';

    return 0;
}

/*
💭 first idea
to use a map but that wasnt the right case 

🧩 key property / invariant
each stack entry = score so far of one open group. Top = innermost unclosed group

✅ key insight
on ')' - pop inner score, score == 0 ? 1 : 2 * inner, add it to the parent(new top)
🔁 recognition cue for next time
nested parentheses + "value depends on what's inside" → stack of partial results

⏱ speed fix for next time
only "()" pairs score: each one adds 2^depth → O(1) space, no stack

*/