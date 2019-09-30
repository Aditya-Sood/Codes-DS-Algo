/*https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monk-and-search-2/*/

#include <iostream>
#include <algorithm>
using namespace std;

void in(int *f)
{
    scanf("%i", f);
}
void out(int f)
{
    printf("%i\n", f);
}

int loc(int x, int *arr, int l, int r)
{
    //Return x or just smaller than x
    //Check for return of first element, which is larger than the required but still unequal
    
    if(r < l)
        return -1;
    else if(r-l == 1)
    {
        /*TEST*/
        if(arr[r] <= x)
            return r;
        else
            return l;
    }
    
    int mid = (l+r)/2;
    
    if(arr[mid] == x)
        return mid;
        
    else if(x < arr[mid])
    {
        return loc(x, arr, l, mid-1);
    }        
    else if(arr[mid] < x)
    {
        if(x < arr[mid+1])
            return mid;
        else
            return loc(x, arr, mid+1, r);
    }
}

int func(int f, int x, int *arr, int n)
{
    //Uses loc to get output
    if(x < arr[0])
        return n;
    else if(arr[n-1] < x)
        return 0;
    
    int l = loc(x, arr, 0, n-1);
    
    if(l != -1 && arr[l] < x)
    {
        //printf("Just greater than: %i\n", arr[l]);
        int temp = l+1;
        while(temp < n && arr[temp] == arr[l])
            temp++;
        l = temp-1;
            
        return (n-1-l);
    }
    
    else if(l != -1 && arr[l] == x)
    {
        if(f == 0)  // >= x
        {
            //Find the leftmost occurence of x
            int temp = l-1;
            while(temp >= 0 && arr[temp] == arr[l])
                temp--;
            l = temp+1;
            
            //printf("loc %i\n", l);
            return (n-1-l+1);
        }
        else if(f == 1) // > x
        {
            int temp = l+1;
            while(temp < n && arr[temp] == arr[l])
                temp++;
            l = temp-1;
        
            return (n-1-l);
        }
    }
    
}

int main()
{
    int n;
    in(&n);
    int arr[n];
    for(int i = 0; i<n; i++)
        in(arr+i);
        
    sort(arr, arr+n);
    
    int q;
    in(&q);
    
    for(int i = 0; i < q; i++)
    {
        int f,x;
        in(&f);
        in(&x);
        
        out(func(f, x, arr, n));
    }
    
    return 0;
}
