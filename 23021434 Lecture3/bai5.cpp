#include<iostream>
using namespace std;

class stack {
	int* array;
	int n;
public:
	stack(int size) {
		array = new int[size];
		n = 0;
	}
	void push()
	{
		int x;
		cin >> x;
		array[n] = x;
		n++;
	}
	void pop()
	{
		n--;
	}
	bool check()
	{
		if (n == 0) return true;
		else return false;
	}
	void print()
	{
		for (int i = 0; i < n; i++)
		{
			cout << array[i] << ' ';
		}
	}
	~stack() {
		delete[] array;
	}
};

int main()
{
	int n;
	cin >> n;
	stack st(100);
	for (int i = 0; i < n; i++)
	{
		st.push();
	}
	st.pop();
	st.pop();

	st.print();

	return 0;
}

