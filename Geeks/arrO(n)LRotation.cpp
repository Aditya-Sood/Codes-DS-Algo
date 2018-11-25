#include <iostream>
using namespace std;

//a < b
int getHCF(int a, int b)
{
    int divsr = a, divdnd = b, rem;
    
    rem = divdnd%divsr;
    
    while(rem != 0)
    {
        divdnd = divsr;
        divsr = rem;
        
        rem = divdnd%divsr;
    }    
    
    return divsr;
}

void rotate(int* arr, int n, int d)
{
    if(d >= n)
    {
        d = d%n;
    }
    
    if(d == 0)
        return;
        
    int hcf = getHCF(d, n);
    
    for(int i = 1; i <= hcf; i++)
    {
        int strtInd = i-1;
        int strtEle = arr[strtInd];
        
        int currInd = strtInd;
        int getInd = (strtInd+d)%n;
        
        while(getInd != strtInd)
        {
            arr[currInd] = arr[getInd];
            
            currInd = getInd;
            getInd = (currInd+d)%n;
        }
        
        arr[currInd] = strtEle;
    }
}

int main()
{
    int n, d;
    cin >> n >> d;
    
    int arr[n];
    for(int i = 1; i <= n; i++)
        arr[i-1] = i;
        
        
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
        
    cout << endl;        
        
    rotate(arr, n, d);
    
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
        
    cout << endl;    
	
	return 0;
}
