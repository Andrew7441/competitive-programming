#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int, int> freq;
        string s = to_string(n);

        for(char i : s){
            freq[i - '0']++;
        }

        int f = INT_MAX;
        int num = INT_MAX;

        for(auto& p: freq){
            if(p.second < f){
                f = p.second;
            }
        }
        for(auto& p: freq){
            if(p.first < num && p.second == f){
                num = p.first;
            }
        }

        return num;
    }
};

int main() {

    Solution S;

    cout << S.getLeastFrequentDigit(723344511);

    return 0;    
}

/*
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int freq[10] = {0};
        string s = to_string(n);

        for(char c : s){
            freq[c - '0']++;
        }

        int minFreq = INT_MAX;
        int ans = 0;

        for(int d = 0; d <= 9; d++){
            if(freq[d] > 0 && freq[d] < minFreq){
                minFreq = freq[d];
                ans = d;
            }
        }

        return ans;
    }
};

*/