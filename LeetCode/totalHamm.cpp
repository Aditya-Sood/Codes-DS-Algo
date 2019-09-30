/* https://leetcode.com/problems/total-hamming-distance/ */

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        bool flag;  //Whether any bit positions left to calculate HD for
        int ct[2];
        
        int total = 0;
        
        do {
            flag = false;
            ct[0] = 0;
            ct[1] = 0;
            
            for(int i = 0; i < n; i++) {
                
                flag = flag || (nums[i] > 0);
                
                if(nums[i]%2 == 0)
                    ct[0]++;
                else
                    ct[1]++;
                
                nums[i] = nums[i] >> 1;
            }
            
            if(!flag)//All zeros, no processing
                continue;
            else
                total += (ct[0]*ct[1]);
            
        }while(flag);
        
        return total;
    }
};