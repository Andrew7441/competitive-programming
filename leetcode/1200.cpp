#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int mindiff = INT_MAX;

        for(int i = 1; i < (int)arr.size(); i++){
            if(arr[i] - arr[i-1] < mindiff){
                mindiff = arr[i] - arr[i-1];
            }
        }

        vector<vector<int>> res;
        for(int i = 1; i < (int)arr.size(); i++){
            if(arr[i] - arr[i-1] == mindiff){
                vector<int> pair;
                pair.push_back(arr[i-1]);
                pair.push_back(arr[i]);
                res.push_back(pair);
            }
        }
        return res; 
    }
};

int main() {
    vector<int> arr = {4, 2, 1, 3};

    Solution S;

    vector<vector<int>> res = S.minimumAbsDifference(arr);

    for(int i = 0; i < (int)res.size(); i++){
        for(int j = 0; j < (int)res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
}

/*
I can see myself getting better in real time and i couldnt be more thankful.
I love myself and i love the suffering which inevitably leads to better 
thought processes and faster thinking. 

I solved this question in under 5 min. I am so proud of myself.
*/