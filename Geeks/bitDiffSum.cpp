#include <iostream>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    for(; t > 0; t--)
    {
        int n;
        scanf("%i", &n);
        
        int* arr = (int*) malloc(sizeof(int)*n);
        
        for(int i = 0; i < n; i++)
            scanf("%i", &arr[i]);
        
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                //cout << arr[i] << '-' << arr[j] << endl;
                if(arr[j] == arr[i]) continue;
                
                int ones = 0;
                //if(arr[j]*arr[i] < 0)   ones++;
                    
                //if(arr[i] < 0) arr[i] *= -1;
                
                //if(arr[j] < 0) arr[j] *= -1;
                    
                int diff = arr[i]^arr[j];
                if(diff < 0)
                {
                    ones++;
                    diff = diff & (2147483647);
                }
                //cout << "Diff " << diff << endl;
                
                while(diff != 0)
                {
                    //cout << "Diff " << diff << endl;
                    if(diff & 1 == 1)
                        ones++;
                    
                    diff /= 2;
                }
                
                //cout << "Ones " << ones << endl;
                //if(i != j)
                ones *= 2;
                    
                sum = (sum + ones)%(1000000007);
            }
        }
        
        free(arr);
        
        printf("%i\n", sum);
    }
	//code
	
	//cout << INT_MAX << endl << INT_MIN << endl;
	return 0;
}