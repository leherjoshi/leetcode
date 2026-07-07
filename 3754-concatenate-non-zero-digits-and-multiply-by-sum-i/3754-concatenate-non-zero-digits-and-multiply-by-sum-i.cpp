class Solution {
public:
    long long sumAndMultiply(int n) {
        string ans=to_string(n);
        long long sum=0;
        long long num=0;
        
        for(int i=0;i<ans.size();i++){
            if((ans[i]-'0')>0){
                num=num*10+(ans[i]-'0');
                sum+=ans[i]-'0';
            }
            
        }
        return sum*num;
    }
};