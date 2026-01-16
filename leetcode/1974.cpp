#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int res = word.size(), point = 'a';

        for(char ch : word){
            res += min(abs(ch - point), 26 - abs(point - ch));
            point = ch;
        }
        return res;
    }
};

int main() {
    Solution S;
    
    cout << S.minTimeToType("abc");
}