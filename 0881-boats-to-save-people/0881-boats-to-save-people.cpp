class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
       sort(people.begin(),people.end());
      
        int cnt=0;
        int n=people.size();
        int j=n-1;

        while(i<=j ){
            int sum1=0;
            while(i<j&&people[j]+people[i]<=limit){
                cnt++;
                i++;
                j--;
            }
            if(i<=j && people[j]<=limit){
                cnt++;
                j--;
            }

           
            

        }return cnt;
    }
};