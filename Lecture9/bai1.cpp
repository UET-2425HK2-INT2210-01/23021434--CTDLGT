#include <iostream>

using namespace std;

// Hàm hoán đổi
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Hàm partition cho quicksort
int partition(double arr[], int low, int high) {
    double pivot = arr[high]; // phần tử chốt
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm quicksort
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    // Cấp phát mảng động
    double* arr = new double[n];

    // Nhập n dòng số thực
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Gọi hàm quicksort
    quickSort(arr, 0, n - 1);

    // In kết quả, các số cách nhau bởi dấu cách
   
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    delete[] arr; // Giải phóng bộ nhớ
    return 0;
}
