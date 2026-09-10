class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int total=accumulate(card.begin(),card.end(),0);
        int windowsum=0;
        
        k=n-k;
        
        for(int i=0;i<k;i++){
            windowsum+=card[i];
        }
        int minwindowsum=windowsum;
        
        for(int i=k;i<n;i++){
            windowsum+=card[i];
            windowsum-=card[i-k];
            minwindowsum=min(windowsum,minwindowsum);
        }
        return total-minwindowsum;
    }
};