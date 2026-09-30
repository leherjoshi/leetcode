class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int size = flowerbed.size();

        // Only one position
        if (size == 1) {
            if (flowerbed[0] == 0) cnt++;
            return cnt >= n;
        }

        // First position
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            cnt++;
        }

        // Middle positions
        for (int i = 1; i < size - 1; i++) {
            if (flowerbed[i - 1] == 0 &&
                flowerbed[i] == 0 &&
                flowerbed[i + 1] == 0) {

                flowerbed[i] = 1;
                cnt++;
            }
        }

        // Last position
        if (flowerbed[size - 1] == 0 &&
            flowerbed[size - 2] == 0) {
            
            cnt++;
        }

        return cnt >= n;
    }
};