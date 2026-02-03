#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for(size_t i = 0; i < s.length(); i++)
            if(s[i] == '?')
                for(s[i] = 'a'; s[i] <= 'c'; ++s[i])
                    if((i == 0 || s[i-1] != s[i]) && (i == s.length() - 1 || s[i+1] != s[i]))
                        break;

        return s;
    }
 
};

int main() {
    Solution S;

    cout << S.modifyString("?zs");
}