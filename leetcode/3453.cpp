#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBelowAreaGreater(vector<vector<int>>& squares, double mid){
        double belowarea = 0;
        double abovearea = 0;

        for(int i = 0; i < (int)squares.size(); i++){
            double bottomY = squares[i][1];
            double side = squares[i][2];
            double topY = bottomY + side;

            if(topY <= mid){
                belowarea += (side * side);
            }else if(bottomY >= mid){
                abovearea += (side * side);
            }else{
                double bottom = mid - bottomY;
                double top = topY - mid;
                belowarea += (bottom * side);
                abovearea += (top * side);
            }
        }
        return belowarea >= abovearea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 0;
        double high = 2e9;
        double precision = 1e-5;

        while(high - low > precision){
            double mid = (low + high) / 2;
            if(isBelowAreaGreater(squares, mid)){
                high = mid; 
            }else{
                low = mid;
            }
        }
        return low;
    }
};

int main() {
    vector<vector<int>> squares{{0,0,1},{2,2,1}};

    Solution S;

    cout << S.separateSquares(squares);
}