class Solution {
    public int findKthLargest(int[] nums, int k) {
         PriorityQueue<Integer>que=new PriorityQueue<>();
        for(int i=0;i<k;i++){
            que.offer(nums[i]);
        }
        for(int i=k;i<nums.length;i++){
            if(nums[i]>que.peek()){
                que.poll();
                que.offer(nums[i]);
            }
        }
        return que.peek();
    }
}