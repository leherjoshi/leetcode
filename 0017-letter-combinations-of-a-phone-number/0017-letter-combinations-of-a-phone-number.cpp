class Solution {
public:
    void combination(vector<string>&res,int i,string current,string digits,unordered_map<char, string> phone){
            if(i==digits.size()){
                res.push_back(current);
                return ;
    }
           
           for(char ch:  phone[digits[i]]){
                combination(res,i+1,current+ch,digits,phone);
            }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits == ""){
            return res;
        }
        unordered_map<char, string> phone = {
    {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
    {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};


        combination(res,0,"",digits,phone);
        return res;
       
    }
};