class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>sh;
        string a;

        while(ss>>a){
            sh.push_back(a);
        }

        reverse(sh.begin(),sh.end());
        string b="";
        for(int i=0;i<sh.size();i++){
            if(i)b+=" ";
            b+=sh[i];
        }
        return b;
    }
};