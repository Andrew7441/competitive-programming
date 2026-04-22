#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/words-within-two-edits-of-dictionary/?envType=daily-question&envId=2026-04-22
*/

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        const int edits = 2;

        for(int i = 0; i < (int)queries.size(); i++){
            string word = queries[i];
            int n = word.size();

            for(int j = 0; j < (int)dictionary.size(); j++){
                string dict = dictionary[j];
                int mism = 0;

                for(int c = 0; c < n; c++){
                    if(word[c] != dict[c]) mism++;
                }
                if(mism <= edits){
                    res.push_back(word);
                    break;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution S;
    
    vector<string> queries{"word","note","ants","wood"};
    vector<string> dictionary{"wood","joke","moat"};

    vector<string> res = S.twoEditWords(queries, dictionary);

    for(string w : res) cout << w << " ";

    return 0;
}

/*
Time complexity: O(q*d*n)
q = # of words in queries
d = # of words in dictionary
n = length of each word ~ both q & d are of same length

Space Complexity: O(q)
q = # of words in queries
*/