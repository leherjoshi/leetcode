class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        
        Deque<Integer> que = new ArrayDeque<>();
        int[] ans = new int[nums.length - k + 1];

        int ind = 0;
//loop for iterate a array
       for(int i = 0; i < nums.length; i++) {

//if there is index in que which is out of slide of k the remove them
        while(!que.isEmpty() && que.peekFirst() <= i - k ){
            que.pollFirst();
        }

//check value of index of fron the last if there is value 
//which is less then a current then remove this index front the last
// of que and keep the  ind  of the geretest value at first
        while(!que.isEmpty() && nums[que.peekLast()] <= nums[i]){
            que.pollLast();
        }

//add a index of curr at the last
        que.offerLast(i);


//store a gerest value in a ans array
        if(i >= k - 1){
            ans[ind++] = nums[que.peekFirst()];
        }


       }
       return ans;
    }
}