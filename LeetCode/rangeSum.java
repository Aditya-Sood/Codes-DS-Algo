/*https://leetcode.com/problems/range-sum-query-immutable/*/

class NumArray {
    
    // sumArr[i] = Sum of elements from index 0 to i
    private int[] sumArr;

    public NumArray(int[] nums) {
        
        int n = nums.length;
        
        sumArr = new int[n];
        
        if(n == 0)
            return;
        
        sumArr[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            sumArr[i] = sumArr[i-1] + nums[i];
        }
            
        
    }
    
    public int sumRange(int i, int j) {
        
        if(i == 0)
            return sumArr[j];
        else
            return (sumArr[j]-sumArr[i-1]);
        
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */