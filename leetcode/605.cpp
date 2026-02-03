#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int x = flowerbed.size();

        for(int i = 0; i < (int)flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                bool leftempty = (i == 0 || flowerbed[i-1] == 0);
                bool rightempty = (i == x - 1 || flowerbed[i + 1] == 0);
                if(leftempty && rightempty){
                    n--;
                    flowerbed[i]= 1;
                    if(n <= 0) return true;
                }
            }
            
        }
        return n <= 0;
    }
};

int main() {

    vector<int> flowerbed{1,0,0,0,1};

    Solution S;

    cout << S.canPlaceFlowers(flowerbed, 1);
    
}