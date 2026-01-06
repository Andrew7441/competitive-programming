#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string& s, int k) {
        reverse(s.begin(), s.begin() + k);
        return s; 
    }
};

int main() {
    Solution Sol;

    string s = "abcd";

    cout << Sol.reversePrefix(s, 2);    

    
}