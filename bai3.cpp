#include<iostream>

using namespace std;

int main()
{
	int a, b;
	
	cin >> a >> b;
	int temp = a < b ? a : b;
	for (int i = temp; i >= 1; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			cout << i;
			break;
		}
	}
	return 0;
}