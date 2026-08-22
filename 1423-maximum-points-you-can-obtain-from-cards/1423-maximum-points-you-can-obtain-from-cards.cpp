class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int res=0;
        int n=card.size();
        for(int i=0;i<n;i++){
            res+=card[i];
        }

        int windowsize=n-k;
        int windowsum=0;
        for(int i=0;i<windowsize;i++){
            windowsum+=card[i];
        }
        int minwindowsum=windowsum;
        for(int i=windowsize;i<n;i++){
            windowsum+=card[i];
            windowsum-=card[i-windowsize];

            minwindowsum=min(minwindowsum,windowsum);
        }
        return res-minwindowsum;
    }
};