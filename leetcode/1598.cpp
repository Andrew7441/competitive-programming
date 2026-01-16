#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;

        for(int i = 0; i < (int)logs.size(); i++){
            if(logs[i] == "./") continue;
            else if(logs[i] == "../"){
                if(res == 0) continue;
                else res--;
            }
            else res++;
        }
        return res; 
    }
};

int main() {
    Solution S;

    vector<string> logs{"d1/","d2/","../","d21/","./"};

    cout << S.minOperations(logs);
}