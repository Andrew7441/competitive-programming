// LeetCode 150 — Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Topic: stack | Tags: math
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> st;
       
       for(string token : tokens){

        if(token == "+" || token == "-" || token == "/" || token == "*"){
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if(token == "+") st.push(a+b);
            else if(token == "-") st.push(a-b);
            else if(token == "/") st.push(a/b);
            else st.push(a*b);
        }else{
            st.push(stoi(token));
        }
       }
       return st.top();
    
    }
};

int main() {
    Solution Sol;
    
    vector<string> tokens{"2","1","+","3","*"};
    
    cout << Sol.evalRPN(tokens);
    
}

/*
💭 First Idea: Operand stack; on an operator pop b then a and push a op b.
🧩 Key Property / Invariant: The stack holds the values of all evaluated sub-expressions not yet consumed.
✅ Key insight: Pop order matters: the second pop is the LEFT operand (a - b, a / b).
🔁 Recognition cue for next time: Postfix / RPN / "evaluate token list" → operand stack.
⏱  Speed fix for next time: Iterate with const string& to avoid copying every token.
🛠  Review: correct; O(n) — Already optimal (C++ '/' truncates toward zero as required).
*/
