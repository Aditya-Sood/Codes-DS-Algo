/*https://leetcode.com/problems/arithmetic-slices/*/

//Refactor for higher readability
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        if(A.size() < 3)
            return 0;
        
        int i; //Starting point for calculations
        int count = 0; //Total slices
        int n = A.size();
        
        for(i = 0; i < n-2;)
        {
            cout << "i = " << i << endl;
            int len = 0;
            
            //Check if valid slice
            if(A[i+2]-A[i+1] == A[i+1]-A[i])
            {
                cout << A[i] << ' ' << A[i+1] << ' ' << A[i+2] << ' ';
                //i = i+2; //As valid
                int d = A[i+1]-A[i];
                len = 3;
                
                //Check longest seq
                int j = i+2;
                for(; j < n-1; j++)
                {
                    if(A[j+1]-A[j] == d)
                    {
                        cout << A[j] << ' ';
                        len++;
                        continue;
                    }
                    else
                    {
                        
                        break;
                    }  
                }                
                i = j;
                
                if(len >= 3)
                    count += ((len-2)*(len-1))/2;
                
                cout << '*' << endl;
            }
            else
            {
                cout << "Miss at: " << A[i] << endl;
                i++;
            }               
        }
        
        return count;
        
    }
};