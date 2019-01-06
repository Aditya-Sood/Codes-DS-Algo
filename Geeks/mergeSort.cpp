#include <iostream>
using namespace std;

void mergesort(int* arr, int l, int r)
{
	if(r <= l)
		return;

	int mid = l + (r-l)/2;

	mergesort(arr, l, mid);
	mergesort(arr, mid+1, r);

	int a = l, b = mid+1;

	int *temp = (int*) malloc(sizeof(int)*(r-l+1));
	int t = 0;

	while(t <= (r-l+1)-1)
	{
		if(a == mid+1)
		{
			while(b <= r)
				temp[t++] = arr[b++];

			break;
		}

		if(b == r+1)
		{
			while(a <= mid)
				temp[t++] = arr[a++];

			break;
		}


		if(arr[a] < arr[b])
		{
			temp[t++] = arr[a++];
		}
		else
		{
			temp[t++] = arr[b++];
		}
	}

	for(int i = l; i <= r; i++)
	{
		arr[i] = temp[i-l];
	}

	free(temp);
}

int main()
{
	int n = 10;
	int a[n];

	for(int i = 0; i < n; i++)
		a[i] = n-i;

	cout << "Original: ";
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';

	cout << endl;

	mergesort(a, 0, n-1);

	cout << "Sorted: ";
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';

	cout << endl;

	return 0;
}