class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        
        for(int i=0;i<s.size();i++  ){
           cout<<s[i]-'a'<<endl;
            sum+=(26-(s[i]-'a'))*(i+1);
        }
        return sum;
    }
};