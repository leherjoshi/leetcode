class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        
        n=len(nums)
        k=k%n
        arr=[0]*n
        for i in range(n):
            arr[(i + k) % n] = nums[i]
            
            #reverse(arr.begin(),arr.begin()+(n-k))
        for i in range(0,n):
            nums[i]=arr[i]

        
        