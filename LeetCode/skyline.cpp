/**
 * https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/
 */

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        if(grid.empty() || grid[0].empty())
            return 0;
        
        vector<int> rmax, cmax;
        
        for(int i = 0; i < grid.size(); i++)
        {
            rmax.push_back(grid[i][0]);
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] > rmax.back())
                    rmax[rmax.size()-1] = grid[i][j];
                
                //cmax 0 - add, else compare
                if(i == 0 || cmax.size() <= j)
                    cmax.push_back(grid[i][j]);
                else
                {
                    if(grid[i][j] > cmax[j])
                        cmax[j] = grid[i][j];   
                }
            }
        }
        
        int sum = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                int min = (rmax[i] < cmax[j]) ? rmax[i] : cmax[j];
                
                sum += min-grid[i][j];
            }
        }
        
        return sum;
        
    }
};