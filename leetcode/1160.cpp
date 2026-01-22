#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int charfreq[26] = {0};
        int res = 0;

        for(char c : chars){
            charfreq[c - 'a']++;
        }

        for(const string& word : words){
            int freq[26] = {0};

            memcpy(freq, charfreq, sizeof(freq));

            bool canform = true;
            for(char c : word){
                if(--freq[c - 'a'] < 0){
                    canform = false;
                    break;
                }
            }

            if(canform) res += word.length();
        }
        return res; 
    }
};
int main() {

    vector<string> words{"cat","bt","hat","tree"};
    string chars{"atach"};

    Solution S;

    cout << S.countCharacters(words, chars);
    
}