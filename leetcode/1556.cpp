#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        vector<char> vs;
        int count = 0;

        reverse(s.begin(), s.end());

        for(char i : s){
            if(count == 3){
                vs.push_back('.');
                count = 0;
            }
            vs.push_back(i);
            count++;
        }

        string res = "";
        reverse(vs.begin(), vs.end());

        for(char i : vs){
            res += i;
        }
        return res;
    }
};

int main() {

    Solution S;

    cout << S.thousandSeparator(1234);
    
}