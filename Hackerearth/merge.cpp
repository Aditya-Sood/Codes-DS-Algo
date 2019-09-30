#include <iostream>
//#include
using namespace std;

void in(int *a)
{
    scanf("%i", a);
}
void out(int a)
{
    printf("%i ", a);
}

int main()
{
    int n;
    in(&n);
    int arr[n];
    for(int i = 0; i < n; i++)
        in(arr+i);
        
    for(int i = 1; i <= n; i++)
    {
        int x = -1, y = -1;
        
        int l = i-1-1, r = i-1+1; //x = l+1, y = r+1
        while(l >= 0)
        {
            //cout << l << endl;
            if(arr[l] > arr[i-1])
            {
                x = l+1;
                break;
            }
            l--;
        }
        while(r < n)
        {
            //cout << r << endl;
            if(arr[i-1] < arr[r])
            {
                y = r+1;
                break;
            }
            r++;
        }
        
        out(x);
        out(y);
        cout << endl;
    }
    
    return 0;
}

-1 -1 
1 -1 
2 4 
2 -1 
4 -1

