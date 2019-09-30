/*https://leetcode.com/problems/climbing-stairs/*/
class Solution {
    public int climbStairs(int n) {
        
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        
        int n1 = 2, n2 = 1, res = 0;
        
        for(int i = 1; i <= n-2; i++)
        {
            res = n1 + n2;  // f(n) = f(n-1) + f(n-2)
            
            n2 = n1;
            n1 = res;
        }
        
        return res;
    }
}