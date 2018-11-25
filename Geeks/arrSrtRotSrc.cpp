#include<iostream>
using namespace std;

//Find the max val index in array
int maxIndBinSrc(int* arr, int l, int r, int p)
{
	if((l <= r) && (arr[l] > arr[r]))
	{
		int mid = (l+r)/2;

		if(*(arr+p) <= *(arr+mid))
		{
			p = mid;

			if(*(arr+mid) < *(arr+r))
				return maxIndBinSrc(arr, l, mid-1, p);

			else if(*(arr+mid) > *(arr+r))
				return maxIndBinSrc(arr, mid+1, r, p);
		}
		
	}
	else
		return p;
}


int main()
{
	int arr[] = {6, 7, 2, 3, 4, 5};

	cout << "Max element at: " << maxIndBinSrc(arr, 0, 5, 2) << endl;

	return 0;
}