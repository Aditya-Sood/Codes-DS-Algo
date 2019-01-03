/*https://leetcode.com/problems/maximum-subarray/*/

class Solution {
    public int maxSubArray(int[] nums) {
        
        int n = nums.length;
        if(n == 1)
            return nums[0];
        
        int[] dp = new int[n];
        dp[0] = nums[0];
        
        // View the array as a recursive structure obtained by repeatedly adding elements at the end
        // dp[i] stores the max sum subarray ending at index i
        
        // Bottom up with tabulation
        for(int i = 1; i < n; i++)
        {
            // Add preceeding subarray to current element only if their sum is positive
            if(dp[i-1] <= 0)
                dp[i] = nums[i];
            
            else //if(dp[i-1] > 0)
            {
                dp[i] = nums[i] + dp[i-1];
            }
        }
        
        int max = Integer.MIN_VALUE;
        for(int val : dp)
        {
            if(val > max)
                max = val;
        }
        
        return max;
        
    }
}