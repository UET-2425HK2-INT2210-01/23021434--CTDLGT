#include <iostream>
#include <vector>
using namespace std;

// Hàm trộn hai đoạn con đã được sắp xếp lại thành một đoạn sắp xếp hoàn chỉnh
void merge(int a[], int left, int right, int mid)
{
    // Tạo hai vector tạm để chứa phần tử của hai đoạn
    vector<int> leftPart(a + left, a + mid + 1);       // left → mid
    vector<int> rightPart(a + mid + 1, a + right + 1); // mid + 1 → right

    int i = 0;      // Chỉ số của leftPart
    int j = 0;      // Chỉ số của rightPart
    int k = left;   // Vị trí bắt đầu ghi vào mảng gốc `a`

    // So sánh phần tử ở hai vector tạm và gán vào mảng `a` theo thứ tự tăng dần
    while (i < leftPart.size() && j < rightPart.size())
    {
        if (leftPart[i] <= rightPart[j])
        {
            a[k++] = leftPart[i++];
        }
        else
        {
            a[k++] = rightPart[j++];
        }
    }

    // Ghi nốt các phần tử còn lại của leftPart (nếu có)
    while (i < leftPart.size())
    {
        a[k++] = leftPart[i++];
    }

    // Ghi nốt các phần tử còn lại của rightPart (nếu có)
    while (j < rightPart.size())
    {
        a[k++] = rightPart[j++];
    }
}

// Hàm mergeSort
void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Tính chỉ số giữa để chia mảng

        // Gọi đệ quy sắp xếp hai nửa
        mergeSort(a, left, mid);       // Sắp xếp nửa trái
        mergeSort(a, mid + 1, right);  // Sắp xếp nửa phải

        // Gộp hai nửa đã sắp xếp
        merge(a, left, right, mid);
    }
}

int main()
{
    int n;
    cin >> n; // Nhập số lượng phần tử của mảng

    vector<int> arr(n); // Khởi tạo vector với n phần tử

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i]; // Nhập từng phần tử
    }

    // Gọi mergeSort, sử dụng data() để truy cập con trỏ mảng nội bộ của vector
    mergeSort(arr.data(), 0, n - 1);

    // In ra mảng sau khi sắp xếp
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
