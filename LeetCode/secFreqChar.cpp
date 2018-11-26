//Given a string, find the second most frequent character in it.
//Expected time complexity is O(n) where n is the length of the input string.

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string input;
	cin >> input;

	std::map<char, int> m;

	for(int i = 0; i < input.size(); i++)
	{
		if(m.find(input[i]) != m.end())
			m[input[i]] += 1;
		else
			m[input[i]] = 1;
	}

	char max = '\0';
	int count = 0;

	map<char, int>::iterator it;
	for(it = m.begin(); it != m.end(); it++)
	{
		if(it->second > count)
		{
			count = it->second;
			max = it->first;
		}
	}

	int secCount = 0;
	char secMax = '\0';
	for(it = m.begin(); it != m.end(); it++)
	{
		if(secCount < it->second && it->second < count)
		{
			secCount = it->second;
			secMax = it->first;
		}
	}

	cout << secMax << " at " << secCount << '\n';

	return 0;
}