#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for(char c : text) mp[c]++;

        return min(mp['b'], min(mp['a'], min(mp['l']/2, min(mp['o']/2, mp['n']))));
    }
};
int main() {
    Solution Sol;
    cout << Sol.maxNumberOfBalloons("loonbalxballpoon");
}