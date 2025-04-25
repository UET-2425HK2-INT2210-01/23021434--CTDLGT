#include <iostream>
using namespace std;

// Hàm phân hoạch kiểu Hoare
int hoarePartition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        for (++i; arr[i] < pivot; ++i);
        for (--j; arr[j] > pivot; --j);

        if (i < j) {
            swap(arr[i], arr[j]);
        }
        else {
            return j;
        }
    }
}

// Hàm sắp xếp nhanh sử dụng phân hoạch Hoare
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int partitionIndex = hoarePartition(arr, left, right);
        quickSort(arr, left, partitionIndex);
        quickSort(arr, partitionIndex + 1, right);
    }
}

int main() {
    int size;
    cin >> size;

    int* numbers = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
    }

    quickSort(numbers, 0, size - 1);

    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    delete[] numbers;
    return 0;
}
