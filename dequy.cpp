#include<iostream>
using namespace std;
int tinh_tong_so_nguyen(int n)
{	
	if (n < 1) {
		return 0;
	}	
	if (n == 1){ // điều kiện dừng			
		return 1;
	}
	return n + tinh_tong_so_nguyen(n - 1);
}
int tinh_giai_thua(int n)
{
	if (n < 1)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return n * tinh_giai_thua(n - 1);
}
int fibonacci(int n)
{
	if (n < 1)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int luy_thua(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	
	return x * luy_thua(x, n - 1);

}
int dem_so(int n)
{
	int count = 1;
	if (n < 10)
	{
		return 1;
	}
	
	return count + dem_so(n / 10);
}
int tinh_tong_1so(int n) {
	if (n == 0)
	{
		return 0;
	}
	return (n % 10) + tinh_tong_1so(n / 10);
}
int dao_nguoc(int n, int x = 0) { //đệ quy đuôi 
	if (n == 0)
		return x;
	return dao_nguoc(n / 10, x * 10 + n % 10);
}int main()
{
	int n;
	int x;
	cout << " x = " << endl;
	cin >> x;
	cout << " n = " << endl;
	cin >> n;
	//cout<<tinh_tong_so_nguyen(n);
	//cout << tinh_giai_thua(n);
	//cout << fibonacci(n);
	//cout << luy_thua(x, n);
	//cout << dem_so(n);
	//cout << tinh_tong_1so(n);
	//cout << dao_nguoc(n);
	return 0;
}