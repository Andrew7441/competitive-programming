#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;

        for(auto w : patterns){
            if(word.find(w) != std::string::npos){
                res++;
            }
        }
        return res; 
    }
};
int main() {
    vector<string> patterns{"a","abc","bc","d"};
    string word{"abc"};

    Solution S;

    cout << S.numOfStrings(patterns, word);
    
}