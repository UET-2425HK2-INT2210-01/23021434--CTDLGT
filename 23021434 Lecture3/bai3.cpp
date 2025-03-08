#include<iostream>
using namespace std;

class queue {
private:
	int arr[1000];
	int n = 0;
public:
	
	void push()
	{
		int x;
		cin >> x;
		arr[n] = x;
		n++;
	}
	
	void del()
	{
		if (check()) return;
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		n--;
	}
	bool check()
	{
		if (n = 0) return true;
		else return false;
	}
	int count()
	{
		return n;
	}

	int value()
	{
		return arr[0];
	}
	
	void print()
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << ' ';
		}
	}
};


int main()
{
	int n;
	cin >> n;
	queue p;
	for (int i = 0; i < n; i++)
	{
		p.push(); 
	}

	cout << p.count(); 
	cout << p.value(); 
	p.del();
	p.del();

	p.print(); 

	return 0;
}


