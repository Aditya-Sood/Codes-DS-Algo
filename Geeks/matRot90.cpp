/* https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/ */

#include <iostream>
using namespace std;

int mat[50][50];

//int k;

void rot90(int a, int b)
{
    //cout << "Entered\n";
    if(a == b || a > b)
        return;
    
    //cout << "Working\n";
    
    for(int i = a; i < b; i++)
    {
        int temp = mat[i][a];
        
        int x = i, y = a;
        for(int j = 1; j < 4; j++)
        {
            //cout << "Shifting\n";
            mat[x][y] = mat[y][b-(x-a)];
            int t = x;
            x = y;
            y = b - (t-a);
        }
        //cout << endl;
        
        mat[x][y] = temp;
    }
    
    //cout << 'a' << a+1 << 'b' << b-1 << endl;
    rot90(a+1, b-1);
}

int main() {
    
    int t;
    cin >> t;
    
    for(; t > 0; t--)
    {
        int n;
        cin >> n;
        //k = n;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> mat[i][j];
                
        rot90(0, n-1);
        
        for(int i = 0; i < n; i++)
        {   for(int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
            
            //cout << endl;
        }
                
        cout << endl;
    }
    
	//code
	return 0;
}