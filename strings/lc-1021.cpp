#include <bits/stdc++.h>
using namespace std;

/*
*/

/* my solution, TC: O(n)  SC: O(n) 
class Solution {
public:
    string removeOuterParentheses(string s) {
        std::string res = "";
        std::vector<std::string> v;
        int cnt = 0;

        for(const auto& c : s) {
            res += c;
            if(c == '(') cnt++;
            else cnt--;

            if(cnt == 0) {
                v.push_back(res);
                res = "";
            }
        }

        for(std::string& s : v){
            s.erase(s.begin());
            s.erase(s.end() - 1);
            res += s;
        }

        return res;
    }
};
*/

// optimized TC: O(n) SC: O(1)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        std::string res = "";

        for(const char& c : s) {
            if(c == '(') {
                if(depth > 0){
                    res += c;    
                }
                depth++;
            }            
            else {
                depth--;
                if(depth > 0) {
                    res += c;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    std::cout << S.removeOuterParentheses("(()())(())") << '\n';
    
    return 0;
}

/*
💭 first idea
🧩 key property / invariant
✅ key insight
🔁 recognition cue for next time
⏱ speed fix for next time
*/