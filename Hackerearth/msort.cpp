#include <iostream>
using namespace std;

/**
* Take arrays, bounds of sorting
* Top down: 
        - Divide until two elements (trivial then)
        - Upwards flow, simply mix up two arrays at a time (in order)
* Returns sorted array
*/

int* msort(int* arr, int l, int r)
{
        if(l >= r)      // Single element array -> trivially sorted
                return arr;

        int mid = (l+r)/2;

        msort(arr, l, mid);
        msort(arr, mid+1, r);

        int* temp = (int*) malloc(r-l+1);

        int pa = l;
        int pb = mid+1;
        for(int i = l; i <= r;)
        {
                if(pa > mid)
                {
                        while(i <= r && pb <= r)
                        {
                                temp[i-l] = arr[pb];
                                i++;
                                pb++;
                        }

                        break;
                }
                else if(pb > r)
                {
                        while(i <= r && pa <= mid)
                        {
                                temp[i-l] = arr[pa];
                                i++;
                                pa++;
                        }
                        
                        break;
                }
                else
                {
                        if(arr[pa] < arr[pb])
                        {
                                temp[i-l] = arr[pa];
                                i++;
                                pa++;
                        }
                        else
                        {
                                temp[i-l] = arr[pb];
                                i++;
                                pb++;
                        }
                }
        }

        for(int i = l; i <= r; i++)
                arr[i] = temp[i-l];

        free(temp);

        return arr;
}

int main()
{
        //int a[] = {11, -12, 123, 14, -11, 12, -123, 814};

        int m;
        cin >> m;

        int a[m];
        for(int i = 0; i < m; i++)
                cin >> a[i];

        for(int ele : a)
                cout << ele << ' ';

        cout << endl;

        int n = sizeof(a)/sizeof(int);
        int* b = msort(a, 0, n - 1);
        int arr[n];
        for(int i = 0; i < n; i++)
                arr[i] = b[i];

        for(int ele : arr)
                cout << ele << ' ';

        cout << endl;

        return 0;
}

