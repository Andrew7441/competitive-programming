#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return -1;

        return max(a.length(), b.length());
    }
    
};

int main() {
    Solution Sol;

    cout << Sol.findLUSlength("aba","cdc");
    
}