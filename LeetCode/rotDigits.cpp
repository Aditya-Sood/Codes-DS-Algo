/*
 * https://leetcode.com/problems/rotated-digits/description/
 */

class Solution {
public:
    int rotatedDigits(int N) {
        
        int res = 0;
        
        for(int X = 1; X <= N;)
        {
            bool good = false;
            int invalid = -1;
            
            int pos = 0, i = X;
            while(i > 0)
            {
                int dig = i%10;
                
                //Invalid digit
                if(dig == 3 || dig == 4)
                {
                    X += 2 * ((int) pow(10, pos));
                    goto outer;
                }
                else if(dig == 7)
                {
                    X += ((int) pow(10, pos));
                    goto outer;
                }
                
                if(dig == 2 || dig == 5 || dig == 6 || dig == 9)
                {
                    good = true;
                }
                
                i = i/10;
                pos++;
            }
            
            if(good)
            {
                res++;
                //cout << X << " ";
            }
                
        
            X++;
            outer:;
        }
        
        return res;
        
    }
};