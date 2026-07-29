class Solution:
    def check(self, nums: List[int]) -> bool:
        n=len(nums)
        if n <= 1:
            return True

        cnt=0

        for index in range(0,n):
            if nums[index]>nums[(index+1)%n]:
                cnt+=1
               

       

        return cnt<=1
        