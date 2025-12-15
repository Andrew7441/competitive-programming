#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int res = 0;

        for(size_t i = 0; i < s.length(); i++){
            if((i == 0 || s[i-1] == ' ') && s[i] != ' '){
                res++;
            }
        }

        return res; 
    }
};

int main() {
    Solution Sol;
    
    string s = "Hello, my name is John";


    cout << Sol.countSegments(s);
}
