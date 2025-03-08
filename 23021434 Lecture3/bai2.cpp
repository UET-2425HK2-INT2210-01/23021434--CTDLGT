#include <iostream>
using namespace std;

double result(int n)
{
	double temp = 1;
	if (n == 0)
	{
		return 1;
	}
	else if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			temp = temp * 2;
		}
		return temp;
	}
	else if (n < 0)
	{
		for (int i = 0; i < (n * (-1)); i++)
		{
			temp = temp / 2;
		}
		return temp;
	}
}

int main()
{
	int n;
	cin >> n;
	cout << result(n);
	return 0;
}

