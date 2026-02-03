#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
      string res = "";
      istringstream ss(sentence);
      int num = 1;
      string word; 
      while(ss >> word){
        char ch = tolower(word[0]);
        if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'o' || ch == 'u' ){
            res += word + "ma";
        }else{
            char first = word[0];
            word.erase(0, 1);
            word.push_back(first);
            res += word + "ma";
        }
        res += string(num, 'a');
        num++;
        res += " ";
      }
      res.pop_back();
      return res;
    }
};

int main() {
    string sentence = "I speak Goat Latin";

    Solution S;

    cout << S.toGoatLatin(sentence) << endl;
}