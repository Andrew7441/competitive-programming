#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<pair<int,int>> cur;
        int prevtime = 0;

        for(auto &s : logs){
            int id = stoi(s.substr(0,s.find(':')));
            int time = stoi(s.substr(s.rfind(':') + 1));

            if(s.find("end") != std::string::npos){
                res[id] += time - prevtime + 1;
                cur.pop();
                prevtime = time + 1;
            }else{
                if(!cur.empty()){
                    res[cur.top().first] += time - prevtime;
                }
                cur.push({id, time});
                prevtime = time;
            }
        }
        return res;
    }
};

int main() {
    Solution S;

    vector<string> logs{"0:start:0","1:start:2","1:end:5","0:end:6"};

    vector<int> res = S.exclusiveTime(2, logs);

    cout << "[ ";
    for(int i : res){
        cout << i << " ";
    }
    cout << "]";
}