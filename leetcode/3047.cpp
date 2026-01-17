#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr){
        long long ans = 0;
        int n = bl.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1;j < n; j++){
                long long bottomx = max(bl[i][0], bl[j][0]);
                long long bottomy = max(bl[i][1], bl[j][1]);

                long long topx = min(tr[i][0], tr[j][0]);
                long long topy = min(tr[i][1], tr[j][1]);

                if(topx < bottomx || topy < bottomy){
                    continue;
                }

                long long height = topy - bottomy;
                long long width = topx - bottomx;
                long long squareSide = min(height, width);
                long long area = squareSide * squareSide;

                ans = max(area, ans);
            }
        }
        return ans;
    }
};

int main() {
    Solution S;

    vector<vector<int>> bottomleft{{1,1},{2,2},{3,1}};
    vector<vector<int>> topright{{3,3},{4,4},{6,6}};

    cout << S.largestSquareArea(bottomleft, topright);
}