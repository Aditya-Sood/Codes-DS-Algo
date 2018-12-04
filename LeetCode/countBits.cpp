/**
 * https://leetcode.com/problems/counting-bits/
 */
class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> one(num+1);
        
        one[0] = 0;
        if(num == 0) return one;
        
        one[1] = 1;
        if(num == 1) return one;
        
        for(int i = 2; i <= num; i++)
        {
            int prev = i - (1 << ((int) log2(i)));
            one[i] = 1 + one[prev];
        }
        
        return one;        
    }
};