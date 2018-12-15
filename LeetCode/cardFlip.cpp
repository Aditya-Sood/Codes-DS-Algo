/*
 * https://leetcode.com/problems/card-flipping-game/description/
*/

class Solution {
public:
    
    void flip(vector<int>& fronts, vector<int>& backs, int pos)
    {
        int temp = fronts[pos];
        fronts[pos] = backs[pos];
        backs[pos] = temp;
    }
    
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        
        int smol = 2001;
        
        //Check for each of the 2n nums (n checks per number)
        
        //Starting with (front as back)
        for(int i = 0; i < fronts.size(); i++)
        {
            int cand = fronts[i];
            
            if(cand == backs[i])
                continue;
            
            bool good = true;
            for(int j = 0; j < backs.size(); j++)
            {
                if(cand == backs[j])
                {
                    if(cand == fronts[j])
                        good = false;
                }
            }
            
            if(good && cand < smol)
                smol = cand;
        }
        
        //Starting with (back as back)
        for(int i = 0; i < backs.size(); i++)
        {
            int cand = backs[i];
            
            if(cand == fronts[i])
                continue;
            
            bool good = true;
            for(int j = 0; j < fronts.size(); j++)
            {
                if(cand == fronts[j])
                {
                    if(cand == backs[j])
                        good = false;
                }
            }
            
            if(good && cand < smol)
                smol = cand;
        }
        
        if(smol == 2001) //No small good num
            return 0;
        
        return smol;
    }
};