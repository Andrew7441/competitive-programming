#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string res = "";
        int sum = 0;

        for(char i : s){
            res += to_string(i - 'a' + 1);
        }

        for(int i = 0; i < k; i++){
            for(char i : res){
                int n = int(i - '0');
                sum += n;
            }
            res = to_string(sum);
            sum = 0;
        }
        return stoi(res);
    }
};

int main() {
    Solution S;

    cout << S.getLucky("iiii", 1);
    
}