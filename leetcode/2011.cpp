#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(string op : operations){
            if(op == "X++" || op == "++X") x++;
            else x--;
        }
        return x;
    }
};

int main() {

    Solution Sol;

    vector<string> operations{"--X","X++","X++"};

    cout << Sol.finalValueAfterOperations(operations);
    
}