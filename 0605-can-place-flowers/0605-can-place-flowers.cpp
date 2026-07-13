class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(m == 1) {
            if(flowerbed[0]) return n == 0;
            else return n <= 1;
        }
        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }

        if(flowerbed[m-1] == 0 && flowerbed[m-2] == 0) {
            flowerbed[m-1] = 1;
            n--;
        }
        for(int i = 1; i < m - 1; ++i) {
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n < 1;
    }
};