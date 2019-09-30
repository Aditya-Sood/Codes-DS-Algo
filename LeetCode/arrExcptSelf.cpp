/* https://leetcode.com/problems/product-of-array-except-self */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> op(n, 1);
        
        for(int i = 1; i < n; i++)
            op[i] = op[i-1]*nums[i-1];
        
        for(int i = n-1, p = 1; i >= 0; i--)
        {
            op[i] *= p;
            p *= nums[i];
        }
            
        
        return op;
    }
};