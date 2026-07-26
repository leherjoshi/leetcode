class Solution {
public:
    int largestInteger(int n, int s) {
        string ans="";
        int sum=0;
        if(s>9*n)return -1;
        for(int i=0;i<n;i++){
            if(sum+9<=s){
                sum+=9;
            ans+='9';}
            else if(sum+8<=s){
                sum+=8;
                ans+='8';
            }
            else if(sum+7<=s){
                sum+=7;
                ans+='7';
            }
            else if(sum+6<=s){
                sum+=6;
                ans+='6';
            }
            else if(sum+5<=s){
                sum+=5;
                ans+='5';
            }
            else if(sum+4<=s){
                sum+=4;
                ans+='4';
            }
            else if(sum+3<=s){
                sum+=3;
                ans+='3';
            }
            else if(sum+2<=s){
                sum+=2;
                ans+='2';
            }
            else if(sum+1<=s){
                sum+=1;
                ans+='1';
            }
            else if(sum+0<=s){
                sum+=0;
                ans+='0';
            }else{
                return -1;
            }
        }
        int a=stoi(ans);
        return a;
    }
};