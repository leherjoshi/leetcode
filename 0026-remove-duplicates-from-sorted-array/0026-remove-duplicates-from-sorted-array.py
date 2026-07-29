class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        arr=[]
        n=len(nums)
        j=0
        for i in range(0,n-1):
           if nums[i]!=nums[i+1]:
            arr.append(nums[i])
            j+=1

        arr.append(nums[-1])

        m=len(arr)
        for i in range(0,m):
            nums[i]=arr[i]

        return(len(arr))

        