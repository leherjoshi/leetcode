class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        int wordLen=words[0].size();
        int numlen=words.size();
        int windowlen=wordLen*numlen;
        int n=s.size();

        unordered_map<string,int>target;
        for(string st:words)target[st]++;

       for(int offset=0;offset<wordLen;offset++){
        int left=offset;
        int count=0;
        unordered_map<string,int>window;
            
            for(int right=offset;right+wordLen<=n;right+=wordLen){
                string w=s.substr(right,wordLen);

                if(target.find(w)==target.end()){
                    window.clear();
                    count=0;
                    left=right+wordLen;
                    continue;
                }
                window[w]++;
                count++;

                while(window[w]>target[w]){
                    string leftword=s.substr(left,wordLen);
                    window[leftword]--;
                    count--;
                    left+=wordLen;
                }

                if(count==numlen){
                    res.push_back(left);
                    string leftword=s.substr(left,wordLen);
                    window[leftword]--;
                    count--;
                    left+=wordLen;
                }

            }
       }
       return res;
    }
};