class Solution:
    def checkString(self, s: str) -> bool:
        n=len(s)
        for i in range(0,n-1):
            if s[i]>s[i+1]:
                return False

        return True

        
        