#include<iostream>
using namespace std;
int main()
{

    
    int arr[100];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            int temp = arr[j];
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << arr[0] + arr[4];

    return 0;
}