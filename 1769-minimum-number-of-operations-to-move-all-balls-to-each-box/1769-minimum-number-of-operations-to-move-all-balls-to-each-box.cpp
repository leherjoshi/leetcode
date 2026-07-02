class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>answer(n,0);
        int ballsl=0;
        int movesl=0;
        int ballsr=0;
        int movesr=0;

        for(int i=0;i<n;i++){
            answer[i]+=movesl;
            ballsl+=boxes[i]-'0';
            movesl+=ballsl;

            int j=n-i-1;
            answer[j]+=movesr;
            ballsr+=boxes[j]-'0';
            movesr += ballsr;
        }
        return answer;
    }
};