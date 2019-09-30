/*https://leetcode.com/problems/house-robber/*/

class Solution {
    public int rob(int[] nums) {
        
        if(nums.length <= 0)
            return 0;
        
        if(nums.length == 1)
            return nums[0];
        
        int a , b;
        
        a = nums[0];
        b = (nums[0] > nums[1]) ? nums[0] : nums[1];
        
        int res = b;
        
        for(int i = 2; i < nums.length; i++)
        {
            int val = nums[i];
            
            res = Math.max(a+val, b);
            
            a = b;
            b = res;
        }
        
        return res;
    }
}