class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        int i=0;
        int j=0;
       vector<string>v;
        while(j<pattern.size()||i<s.size()){
            
            string ms="";
            while(i<s.size()&&s[i]!=' '){
                ms+=s[i];
                i++;
            }
            if(ms.size()==0)return false;
            v.push_back(ms);
            if(mp1.find(pattern[j])!=mp1.end()){
                if(mp1[pattern[j]]!=ms)return false;
            }
            if(mp2.find(ms)!=mp2.end()){
                if(mp2[ms]!=pattern[j])return false;
            }
            mp1[pattern[j]]=ms;
            mp2[ms]=pattern[j];
            
            
            i++;
            j++;
        }
        for(string sf:v)cout<<sf<<endl;
        //cout<<v.size();
        if(pattern.size()!=v.size())return false;
        
        return true;
    }
};