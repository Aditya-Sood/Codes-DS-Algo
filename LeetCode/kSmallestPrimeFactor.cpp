/* https://leetcode.com/problems/k-th-smallest-prime-fraction/ */

bool compInt(int a, int b)
    {
        return (a < b);
    }

class Solution {
public:
    
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), compInt);
        
//         for(int i = 0; i<n; i++)
//             cout << a[i] << ' ';
        
        //cout << endl;
        
        vector<int> res(2, 0);
        
        if(k == 1)
        {
            res[0] = a[0];
            res[1] = a[n-1];
            
            return res;
        }
        
        int denom[n-1];
        for(int i = 0; i<n-1; i++)    
            denom[i] = n-1;
            
        int min;
        double val;
        min = 0;
        while(k > 0)
        {
            val = ((double) a[min])/a[denom[min]];
            
            for(int i = 1; i < n-1; i++)
            {
                if(denom[i] > i && val > ((double) a[i])/a[denom[i]])
                {
                    min = i;
                    val = ((double) a[min])/a[denom[min]];
                }    
                
            }
            
            cout << a[min] << a[denom[min]] << endl;
            
            k--;
            
            if(k > 0)   denom[min] -= 1;
        }
        
        res[0] = a[min];
        res[1] = a[denom[min]];
        
        return res;
    }
    
};