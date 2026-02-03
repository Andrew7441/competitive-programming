#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        int count = 0;
        string res = "";

        for(int i = s.size() - 1; i >= 0; i--){
            if(count == 3){
                res.push_back('.');
                count = 0;
            }
            res.push_back(s[i]);
            count++;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main() {

    Solution S;

    cout << S.thousandSeparator(1234);
    
}