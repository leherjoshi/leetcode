class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());

        int sum=skill[0]+skill[skill.size()-1];
        long long ans=skill[0]*skill[skill.size()-1];

        for(int i=1;i<(skill.size())/2;i++){

            if(skill[i]+skill[skill.size()-i-1]!=sum)return -1;
            ans+=skill[i]*skill[skill.size()-i-1];

        }
        return ans;
    }
};