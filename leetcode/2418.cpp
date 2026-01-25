#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string, int>> v;

        for(int i = 0; i < n; i++){
            v.push_back({names[i], heights[i]});
        }
        sort(v.begin(), v.end(),[](const pair<string, int>& a, const pair<string, int>& b){
            return a.second > b.second;
        });

        vector<string> res(n);
        for(int i = 0; i < n; i++){
            res[i] = v[i].first;
        }

        return res;
    }
};

int main() {
    vector<string> names{"Mary","John","Emma"};
    vector<int> heights{180,165,170};

    Solution S;

    vector<string> New_Names  = S.sortPeople(names, heights);

    for(auto i : New_Names)
        cout << i << " ";

    
}