#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> charcount;
        for(char i : word){
            charcount[i]++;
        }

        unordered_map<int, int> freq;
        for(auto &p : charcount){
            freq[p.second]++;
        }

        if(freq.size() > 2) return false;

        if(freq.size() == 1){
            int f = freq.begin()->first;
            int c = freq.begin()->second;
            return (f == 1 || c == 1);
        }

        auto it = freq.begin();
        
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;

        if(f1 > f2){
            swap(f1, f2);
            swap(c1, c2);
        }

        if(f1 == 1 && c1 == 1) return true;

        if(f2 - f1 == 1 && c2 == 1) return true;

        return false;
    }
};

int main() {

    Solution S;
    
    cout << boolalpha;
    cout << S.equalFrequency("abcc");

    return 0;
}