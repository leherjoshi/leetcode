class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        
        for(int x : freq){
            if(x > (n+1)/2) return "";
        }
        string ans="";
       vector<int>a(n);
       
        int i=0;

        vector<pair<int,int>> order; 
for(int f = 0; f < 26; f++){
    if(freq[f] > 0){
        order.push_back({freq[f], f});
    }
}

sort(order.begin(), order.end(), greater<pair<int,int>>());

// order[0] now has the highest-frequency letter first
    for(int f=0;f<order.size();f++){
       while(order[f].first > 0){
                a[i]=order[f].second;
                order[f].first--;
                i+=2;
                if(i>=n) i=1;
            }
      }
      for(int i=0;i<a.size();i++){
        ans+=a[i]+'a';
      }
      return ans;
    }
};