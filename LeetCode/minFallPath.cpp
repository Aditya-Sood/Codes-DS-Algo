/**
 * https://leetcode.com/problems/minimum-falling-path-sum/
 */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        int n = A.size();
        short tab[n][n];
        
        for(int i = 0; i < n; i++)
            tab[n-1][i] = A[n-1][i];
        
        for(int i = n-2; i >= 0; i--)
            for(int j = 0; j < n; j++)
            {
                int min = 101;
                
                if(j-1 >= 0 && tab[i+1][j-1] < min)
                    min = tab[i+1][j-1];
                
                if(tab[i+1][j] < min)
                    min = tab[i+1][j];
                
                if(j+1 < n && tab[i+1][j+1] < min)
                    min = tab[i+1][j+1];   
                
                tab[i][j] = A[i][j] + min;
            }
        
        int minfall = (100*n) + 1;
        
        // for(int i = 0; i < n; i++)
        //     cout << tab[0][i] << " ";
        
        for(int i = 0; i < n; i++)
            if(tab[0][i] < minfall)
                minfall = tab[0][i];
        
        return minfall;        
    }
};