/*
//https://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/

#include <iostream>
using namespace std;

int getVal(int* arr, int n)
{
	val = 0;
	for(int i = 0; i < n; i++)
	{
		val *= 10;
		val += arr[i];
	}

	return val;
}

int* consArr(int* arr, int n)
{

}

int smallNextPal(short int ipArr, int n)
{
	short int palArr[n];
	for(int i = 0; i < n/2; i++)
	{
		palArr[i] = ipArr[i];
		palArr[n-1-i] = ipArr[i];
	}

	int ip = getVal(ipArr, n), pal = getVal(palArr, n);

	if(ip < pal)
	{
		cout << pal;
	}
	else if(ip == pal)
	{
		if(n == 1)
		{
			if(ipArr[0] != 9)
			{
				cout << ipArr[0]+1;
			}
			else
				cout << 11;
		}
		else
		{
			int ip1[n+1] //for ip+1
		}
	}
	else if(pal < ip)
	{	
		if(n % 2 == 0)
		{
			if(ipArr[n/2] != ipArr[(n/2)-1])
			{
				int n = (ipArr[(n/2)-1] > ipArr[(n/2)]) ? ipArr[(n/2)-1] : ipArr[(n/2)];
				ipArr[(n/2)-1] = n;
				ipArr[(n/2)] = n;

				for(int i = 0; i < n/2; i++)
				{
					palArr[i] = ipArr[i];
					palArr[n-1-i] = ipArr[i];
				}
			}
			else
			{
				ipArr[(n/2)] = ++ipArr[(n/2)]%10;
				ipArr[(n/2)-1] = ++ipArr[(n/2)-1]%10;
				
				if()
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	short int ipArr[n];
	for(int i = 0; i < n; i++)
		cin >> ip[i];

}

*/