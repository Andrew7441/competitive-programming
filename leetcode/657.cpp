#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, d = 0, l = 0, r = 0;

        for(int i = 0; i < (int)moves.length(); i++){
            if(moves[i] == 'U') u++;
            else if(moves[i] == 'D') d++;
            else if(moves[i] == 'L') l++;
            else r++;
        }

        if(u - d == 0 && l - r == 0) return true;

        return false; 
    }
};

int main() {
    Solution S;

    cout << boolalpha;
    cout << S.judgeCircle("UD");

    return 0;
}