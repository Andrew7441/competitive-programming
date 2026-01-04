#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        int prod = 1, sum = 0;

        for(char i : s){
            prod *= i - '0';
            sum += i - '0';
        }
        return prod - sum; 
    }
};

int main() {
    Solution Sol;

    cout << Sol.subtractProductAndSum(4421) << endl;
    
}