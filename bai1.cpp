#include<iostream>
#include<string>
using namespace std;
	
void reverse(string str)
{
	for (int i = str.length() - 1; i >= 0; i--)
	{
		cout << str[i];
	}
}
int main()
{
	string str;

	getline(cin , str);

	reverse(str);

	return 0;


}