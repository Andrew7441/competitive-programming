#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        
        for(char c : s){
            int n = res.size();

            if(n < 2 || !(res[n-1] == c && res[n-2] == c)){
                res+=c;
            }
        }
        return res; 
    }
};

int main() {
    Solution Sol;

    cout << Sol.makeFancyString("leeetcode");

}