class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        sorted_str=strs[:]

        for i in range(len(strs)):
            sorted_str[i]=''.join(sorted(sorted_str[i]))

        mp={}

        for i in range(len(sorted_str)):
            if sorted_str[i] not in mp:
                mp[sorted_str[i]]=[]
            mp[sorted_str[i]].append(strs[i])
        

        ans=[]

        for key in mp:
            ans.append(mp[key])

        return ans

        