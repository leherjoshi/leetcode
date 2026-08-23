class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n / 2;

        int leftsum = 0, rightsum = 0;
        int leftq = 0, rightq = 0;

        for (int i = 0; i < mid; i++) {
            if (num[i] == '?')
                leftq++;
            else
                leftsum += num[i] - '0';
        }

        for (int i = mid; i < n; i++) {
            if (num[i] == '?')
                rightq++;
            else
                rightsum += num[i] - '0';
        }

        int diff = leftsum - rightsum;
        int qdiff = leftq - rightq;

        if (qdiff == 0)
            return diff != 0;

        if (qdiff > 0) {
            if (qdiff % 2 == 1 && diff == 0)
                return true;

            return diff + (qdiff / 2) * 9 != 0;
        }

        return diff - ((-qdiff) / 2) * 9 != 0;
    }
};