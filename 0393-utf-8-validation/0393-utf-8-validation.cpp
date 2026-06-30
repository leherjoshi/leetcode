class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=data.size();
       int i=0;
        while(i<n){

            int byte=0;

            if((data[i]>>7)==0)
                byte=1;
            else if((data[i]>>5)==0b110)
                    byte=2;
            else if((data[i]>>4)==0b1110)
                byte=3;
                else if((data[i]>>3)==0b11110){
                    byte=4;
                }
            else{
                return false;
            }
            if(n-byte<i)return false;

            for(int j=1;j<byte;j++){
                if((data[i+j]>>6)!=0b10)return false;
            }
            i+=byte;
        }
        return true;
    }
};