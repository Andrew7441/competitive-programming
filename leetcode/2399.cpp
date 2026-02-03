#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> firstpos(26, -1);

        for(int i = 0; i < (int)s.size(); i++){
            int idx = s[i] - 'a';
            if(firstpos[idx] == -1){
                firstpos[idx] = i;
            }else{
                if(i - firstpos[idx] - 1 != distance[idx]){
                    return false; 
                }
            }
        }
        return true; 
    }
};

int main() {
    cout << boolalpha;
    Solution Sol;
    vector<int> distance{1,3,0,5,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    cout << Sol.checkDistances("abaccb", distance);

    
}